const fs = require('fs');
const express = require('express');
const { ApolloServer, UserInputError } = require('apollo-server-express');
const { GraphQLScalarType } = require('graphql');
const { Kind } = require('graphql/language');
const { MongoClient } = require('mongodb');

let db;

async function listTravellers()
{
  const travellers = await db.collection('travellers').find({}).toArray();
  return travellers;
}

/**
 * This function was created for the use in the GraphQL Playground 
 * hence it is not called from the front-end side.
 * @returns blacklist
 */
async function listBlackListTravellers()
{
  const blacklist = await db.collection('blacklist').find({}).toArray();
  return blacklist;
}

/**
 * Checks whether a blacklisted traveler with the given phone number exists or not.
 * In order to ensure proper authentication and avoid any issues with multiple people
 * registering the same phone number with different names, we have updated the blacklist 
 * functionality to only include the phone number if there is a match.
 * @returns {boolean} Returns true if a matching record exists, false otherwise.
 */
async function findBlacklistTravellerByPhone(_, { target })
{
  const blacklistIterable = await db.collection('blacklist').find({phone: target.phone});
  const blacklist = await blacklistIterable.toArray();
  return blacklist.length > 0;
}

function inputValidate(input) {
  const errors = [];
  console.log("input.name: ", input.name);

  if (!input.name) {
    errors.push('Field "name" must not be empty.');
  }
  if(input.phone.toString().length != 8){
    errors.push('Field "phone" must be 8 digits.');
  }
  if (errors.length > 0) {
    throw new UserInputError('Invalid input(s): ' + errors);
  }
}

async function addTraveller(_, { ticket })
{	
  console.log("Adding traveller", {ticket});
  inputValidate(ticket);

  async function getNextSequence(name) {
    const result = await db.collection('counters').findOneAndUpdate(
      { _id: name },
      { $inc: { current: 1 } }, 
      { returnOriginal: false },
    );
    return result.value.current;
  }
  ticket.id = await getNextSequence('travellers');
  ticket.bookingTime = new Date();

  const result = await db.collection('travellers').insertOne(ticket);
  const savedTicket = await db.collection('travellers').findOne({_id: result.insertedId});
  console.log("savedTicket: ", savedTicket);
  return savedTicket;
}

const GraphQLDate = new GraphQLScalarType({
  name: 'GraphQLDate',
  description: 'A Date() type in GraphQL as a scalar',
  serialize(value) {
    return value.toISOString();
  },
  parseValue(value) {
    console.log(value)
    const dateValue = new Date(value);
    return isNaN(dateValue) ? undefined : dateValue;
  },
  parseLiteral(ast) {
    if (ast.kind == Kind.STRING) {
      const value = new Date(ast.value);
      return isNaN(value) ? undefined : value;
    }
  },
});

async function deleteTraveller(_, {id})
{
  console.log("Deleting a specific traveller", id);
  const result = await db.collection('travellers').deleteOne({id});

	async function getNextSequence(name) {
	  const result = await db.collection('counters').findOneAndUpdate(
	    { _id: name },
	    { $inc: { current: -1 } }, 
	    { returnOriginal: false },
	  );
	  return result.value.current;
	}
  
  await getNextSequence('travellers');

  await db.collection('travellers').updateMany(
    { id: { $gt: id } },
    { $inc: { id: -1 } }
  );

  return result.deletedCount == 1;
}

async function addBlacklistTraveller(_, {target}){
  console.log("Adding a traveller into the blacklist", target);
  inputValidate(target);

  const isSameNumber = await db.collection('blacklist').findOne({phone: target.phone});
  const isSamePair = await db.collection('blacklist').findOne({name: target.name, phone: target.phone});
  if (isSamePair) {
    throw new Error('The traveller has already been blacklisted (Name & Phone)');
  }else if (isSameNumber){
    throw new Error('This phone number has already been registered');
  }

  var retval = await db.collection('blacklist').insertOne(target);
  console.log(retval);

  return retval.insertedCount == 1;
}

const resolvers = {
  Query: {
    listTravellers,
    listBlackListTravellers,
    findBlacklistTravellerByPhone,
  },
  Mutation: {
    addTraveller,
    deleteTraveller,
    addBlacklistTraveller,
  },
  GraphQLDate,
};

const app = express();
app.use(express.static('public'));

const server = new ApolloServer({
  typeDefs: fs.readFileSync('./server/travellerschema.graphql', 'utf-8'),
  resolvers,
  formatError: error => {
    console.log(error);
    return error;
  },
});
server.applyMiddleware({ app, path: '/graphql' });

async function connectToDb() {
  const url = 'mongodb://localhost/tickettoride';
  const client = new MongoClient(url, { useNewUrlParser: true });
  await client.connect();
  console.log('Connected to Ticket To Ride MongoDB at', url);
  db = client.db();
}

(async function () {
  try {
    await connectToDb();
    app.listen(3000, function () {
      console.log('App started on port 3000');
    });
  } catch (err) {
    console.log('ERROR:', err);
  }
})();
