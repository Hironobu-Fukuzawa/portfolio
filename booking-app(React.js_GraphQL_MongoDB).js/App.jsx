
const dateRegex = new RegExp('^\\d\\d\\d\\d-\\d\\d-\\d\\d');
function jsonDateReviver(key, value) {
  if (dateRegex.test(value)) return new Date(value);
  return value;
}

async function graphQLFetch(query, variables = {}) {
  try {
    const response = await fetch('/graphql', {
      method: 'POST',
      headers: { 'Content-Type': 'application/json'},
      body: JSON.stringify({ query, variables })
    });
    const body = await response.text();
    const result = JSON.parse(body, jsonDateReviver);

    if (result.errors) {
      const error = result.errors[0];
      if (error.extensions.code == 'BAD_USER_INPUT') {
        alert(`${error.message}`);
      } else {
        alert(`${error.extensions.code}: ${error.message}`);
      }
    }
    return result.data;
  } catch (e) {
    alert(`Error in sending data to server: ${e.message}`);
  }
}

async function checkBlacklist(target) {
  const query = `query checkBlacklist($target: InputTarget!){
    findBlacklistTravellerByPhone(target: $target)
  }`;
  const response = await graphQLFetch(query, {target});
  return response.findBlacklistTravellerByPhone ;
}

function TravellerRow(props) {
  const traveller = props.traveller;
  return (
    <tr>
      <td>{traveller.id}</td>
      <td>{traveller.name}</td>
      <td>{traveller.phone}</td>
      <td>{traveller.bookingTime.toDateString()}</td>
    </tr>
  );
}

function Display(props) {
  const travellerRows = props.travellers.map(i =>
    <TravellerRow key={i.id} traveller={i} />
  );

  return (
    <table className="bordered-table">
      <thead>
        <tr>
          <th>ID</th>
          <th>Name</th>
          <th>Phone</th>
          <th>Booking Time</th>
        </tr>
      </thead>
      <tbody>
        {travellerRows}
      </tbody>
    </table>
  );
}

class Add extends React.Component {
  constructor() {
    super();
    this.handleSubmit = this.handleSubmit.bind(this);
  }

  handleSubmit(e) {
    e.preventDefault();
    const form = document.forms.addTraveller;
    const ticket = {
      name: form.travellername.value,
      phone: form.travellerphone.value,
    }
    this.props.bookTraveller(ticket);
    form.travellername.value = "";
    form.travellerphone.value = "";
  }

  render() {
    return (
      <form name="addTraveller" onSubmit={this.handleSubmit}>
        <input type="text" name="travellername" placeholder="Name" />
        <input type="phone" name="travellerphone" placeholder="Phone Number" />
        <button>Add</button>
      </form>
    );
  }
}

class Delete extends React.Component {
  constructor() {
    super();
    this.handleSubmit = this.handleSubmit.bind(this);
  }

  handleSubmit(e, travellerId) {
    e.preventDefault();
    this.props.deleteTraveller(travellerId);
  }

  render() {
    const travellerRows = this.props.travellers.map(i =>
      <tr key={i.id}>
        <td>{i.id}</td>
        <td>{i.name}</td>
        <td>{i.phone}</td>
        <td>
          <form name="deleteTraveller" onSubmit={(e) => this.handleSubmit(e, i.id)}>
            <button>Delete</button>
          </form>
        </td>
      </tr>
    );

    return (
      <table className="bordered-table">
        <thead>
          <tr>
            <th>ID</th>
            <th>Name</th>
            <th>Phone</th>
            <th>Deletion</th>
          </tr>
        </thead>
        <tbody>
          {travellerRows}
        </tbody>
      </table>
    );
  }
}

class Blacklist extends React.Component {
  constructor() {
    super();
    this.handleSubmit = this.handleSubmit.bind(this);
  }

  handleSubmit(e) {
    e.preventDefault();
    const form = document.forms.blacklistTraveller;
    const target ={
      name: form.blacklistname.value,
      phone: form.blacklistphone.value,
    }
    this.props.blacklistTraveller(target);
    form.blacklistname.value = "";
    form.blacklistphone.value = "";
  }

  render() {
    return (
      <form name="blacklistTraveller" onSubmit={this.handleSubmit}>
        <input type="text" name="blacklistname" placeholder="Name" />
        <input type="phone" name="blacklistphone" placeholder="Phone Number" />
        <button>Blacklist</button>
      </form>
    );
  }
}

class Homepage extends React.Component {
	constructor() {
	super();
	}
	render(){
    const Dot = ({ value }) => (
      <div
        style={{
          width: '50px',
          height: '50px',
          backgroundColor: value === 1 ? 'black' : 'transparent',
          boxSizing: 'border-box',
        }}
      />
    );    

    const DotMatrix = ({ data }) => (
      <div>
        {data.map((row, rowIndex) => (
          <div key={rowIndex} style={{ display: 'flex' }}>
            {row.map((value, colIndex) => (
              <Dot key={colIndex} value={value} />
            ))}
          </div>
        ))}
      </div>
    );
    
    const drawingData = [
      [0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0],
      [0,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0],
      [0,0,0,0,1,0,0,0,0,1,0,1,1,0,1,1,1,1,0,0,1,0,0,1,0,1,1,1,1,0,1,0,1,0,1,1,1,1,0,1,0,1,1,0,1,0,0,0,1,0,0,0],
      [0,0,0,0,1,0,0,0,0,1,1,0,0,0,1,0,0,1,0,0,1,0,0,1,0,1,0,0,0,0,1,0,1,0,1,0,0,0,0,1,1,0,0,0,0,1,0,1,0,0,0,0],
      [0,0,0,0,1,0,0,0,0,1,0,0,0,0,1,0,0,1,0,0,1,0,0,1,0,1,1,1,1,0,1,0,1,0,1,1,1,1,0,1,0,0,0,0,0,0,1,0,0,0,0,0],
      [0,0,0,0,1,0,0,0,0,1,0,0,0,0,1,0,0,1,0,0,1,0,0,1,0,1,0,0,0,0,1,0,1,0,1,0,0,0,0,1,0,0,0,0,0,1,0,1,0,0,0,0],
      [0,0,0,0,1,0,0,0,0,1,0,0,0,0,1,1,1,1,1,0,1,1,1,1,0,1,1,1,1,0,1,0,1,0,1,1,1,1,0,1,0,0,0,0,1,0,0,0,1,0,0,0],
    ];
    
	return (
    <div>
      <DotMatrix data={drawingData} />
    </div>);
	}
}

class TicketToRide extends React.Component {
  constructor() {
    super();
    this.state = { travellers: [], selector: 1};
    this.bookTraveller = this.bookTraveller.bind(this);
    this.deleteTraveller = this.deleteTraveller.bind(this);
    this.blacklistTraveller = this.blacklistTraveller.bind(this);
  }

  setSelector(value)
  {
    this.setState({selector: value});
  }
  componentDidMount() {
    this.loadData();
  }

  async loadData() {
    const query = `query {
      listTravellers {
        id name phone bookingTime
      }
    }`;   
    const data = await graphQLFetch(query);
    if (data) {
      this.setState({travellers: data.listTravellers});
    }
  }

  async bookTraveller(ticket) {
    const isBlacklist = await checkBlacklist(ticket);
    try{
      if(isBlacklist){
        throw new Error("Cannot book a traveller - it is blacklisted.");
      }
      const mutation = `mutation addTraveller($ticket: InputTicket!) {
        addTraveller(ticket: $ticket){
          id
        }
      }`;
      const response = await graphQLFetch(mutation, { ticket });
      console.log("Resposen from GQL server: ", {response});
      if(response){
        this.loadData();
      }
    } catch (e) {
      alert(`Error in booking the traveller : ${e.message}`);
    }
  }

  async deleteTraveller(id) {
    const mutation = `mutation deleteTraveller($id: Int!) {
      deleteTraveller(id: $id)  
    }`;
    const response = await graphQLFetch(mutation, {id});
    console.log("Resposen from GQL server: ", {response});
    if(response){
      this.loadData();
    }
    console.log("Response from GQL server: ", response);
  }

  async blacklistTraveller(target) {
    const query = `mutation addBlacklist ($target: InputTarget!) {
      addBlacklistTraveller(target: $target)
    }`;
    const response = await graphQLFetch(query, {target});
    if(response){
      this.loadData();
    }
    console.log("Response from GQL server: ", response);
  }

  render() {
    return (
      <div>
        <h1>Ticket To Ride</h1>
	<div>
        <button onClick={()=>this.setSelector(1)}>Homepage</button>
        <button onClick={()=>this.setSelector(2)}>Display Travellers</button>
        <button onClick={()=>this.setSelector(3)}>Add Traveller</button>
        <button onClick={()=>this.setSelector(4)}>Delete Traveller</button>
        <button onClick={()=>this.setSelector(5)}>Blacklist Traveller</button>
	</div>
	{
		this.state.selector === 1? <Homepage />:<hr/>
	}
	{
		this.state.selector === 2? <Display travellers={this.state.travellers} />:<hr/>
	}
	{
		this.state.selector === 3? <Add bookTraveller={this.bookTraveller} />: <hr/>
	}
	{
		this.state.selector === 4? <Delete deleteTraveller={this.deleteTraveller} travellers={this.state.travellers} />: <hr/>
	}
	{
		this.state.selector === 5? <Blacklist blacklistTraveller={this.blacklistTraveller} />: <hr/>
	}
      </div>
    );
  }
}

const element = <TicketToRide />;

ReactDOM.render(element, document.getElementById('contents'));
