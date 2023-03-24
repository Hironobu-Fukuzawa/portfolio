// Student ID: A0255967J
// Student Name: Hironobu Fukuzawa

const initialTravellers = [
  {
    id: 1,
    name: 'Jack',
    phone: 88885555,
    bookingTime: getCurrentDateTimeString(new Date()),
    gender: 0
  },
  {
    id: 2,
    name: 'Rose',
    phone: 88884444,
    bookingTime: getCurrentDateTimeString(new Date()),
    gender: 1
  },
  {
    id: 3,
    name: 'Hisoka',
    phone: 99999999,
    bookingTime: getCurrentDateTimeString(new Date()),
    gender: 2
  },
];

function getCurrentDateTimeString(now) {
  const year = now.getFullYear();
  const month = ('0' + (now.getMonth() + 1)).slice(-2);
  const day = ('0' + now.getDate()).slice(-2);
  const hours = ('0' + now.getHours()).slice(-2);
  const minutes = ('0' + now.getMinutes()).slice(-2);
  return `${year}-${month}-${day}-${hours}${minutes}`;
}

function TravellerRow(props) {
  const traveller = props.traveller;
  let gender;
  if(traveller.gender === 0){
    gender = 'Male';
  }else if(traveller.gender === 1){
    gender = 'Female';
  }else if(traveller.gender === 2){
    gender = 'Others';
  }

  return (
    <tr>
      <td>{traveller.id}</td>
      <td>{traveller.name}</td>
      <td>{traveller.phone}</td>
      <td>{traveller.bookingTime.toString()}</td>
      <td>{gender}</td>
    </tr>
  );
}

function Display(props) {
  const travellers = props.travellers;

  return (
    <table className="bordered-table">
      <thead>
        <tr>
          <th>ID</th>
          <th>Name</th>
          <th>Phone</th>
          <th>Booking Time</th>
          <th>Gender</th>
        </tr>
      </thead>
      <tbody>
        {travellers.map(traveller => (
          <TravellerRow key={traveller.id} traveller= {traveller} />
        ))}
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
    const traveller = {
      name: e.target.elements.travellername.value,
      phone: e.target.elements.phone.value,
      gender: e.target.elements.gender.value
    };
    this.props.bookTraveller(traveller);
  }

  render() {
    return (
      <form name="addTraveller" onSubmit={this.handleSubmit}>
        {this.props.travellers?.length < 50 ?
          <>
            <input type="text" name="travellername" placeholder="Name" />
            <input type="text" name="phone" placeholder="Phone" />
            <select name="gender">
              <option value="0">Male</option>
              <option value="1">Female</option>
              <option value="2">Others</option>
            </select>
            <button>Add</button>
          </>
          : <div style={{ color: 'red' }}>The maximum number of seats has already been booked.</div>
        }
      </form>
    );
  }
}

class Delete extends React.Component {

  constructor() {
    super();
    this.handleSubmit = this.handleSubmit.bind(this);
  }

  handleSubmit(e) {
    e.preventDefault();
    const id = e.target.elements.travellername.value;
    const selectedTraveller = this.props.travellers.find(traveller => 
      traveller.id === parseInt(id)
    );
    if (selectedTraveller) {
      this.props.deleteTraveller(selectedTraveller);
    }
  }

  render() {
    return (
      <form name="deleteTraveller" onSubmit={this.handleSubmit}>
        {this.props.travellers?.length > 0 ?
          <>
            <select name="travellername">
              {this.props.travellers.map(traveller => (
                <option key={traveller.id} value={traveller.id}>
                  {traveller.name}
                </option>
              ))}
            </select>
            <button>Delete</button>
          </>
          : <div style={{ color: 'red' }}>No travellers found.</div>
        }
      </form>
    );
  }
}

function DisplayFreeSeats(props) {
  const reservedseats = props.state.reservedseats;
  const totalseats = props.state.totalseats;
  const freeSeats = totalseats - reservedseats;
  const reservedSeatsArray = Array.from({ length: reservedseats }, (_, index) => index);
  const freeSeatsArray = Array.from({ length: freeSeats }, (_, index) => index);
  const rows = Math.ceil(totalseats / 10);
  const seats = [];

  for (let i = 0; i < rows; i++) {
    const row = [];
    let oneline = <div key={i} style={{ display: 'flex', flexDirection: 'row' }}>{row}</div>

    for (let j = 0; j < 10; j++) {
      const seatNumber = i * 10 + j;
      let margin = j === 4 ? '5px 15px 5px 5px' : j === 5 ? '5px 5px 5px 15px' : '5px';
      let divEmpty = <div key={seatNumber} style={{ backgroundColor: 'gray', height: '40px', width: '40px', margin: margin, border: '1px solid black' }} />
      let divReserved = <div key={seatNumber} style={{ backgroundColor: 'white', height: '40px', width: '40px', margin: margin, border: '1px solid black' }} />

      if (reservedSeatsArray.includes(seatNumber)) {
        row.push(divEmpty);
      } else {
        row.push(divReserved);
      }
    }
    seats.push(oneline);
  }

  return (
    <div>
      <h2>AVAILABLE SEATS: {freeSeats} SEATS FREE Out Of {totalseats} Total</h2>
      <div style={{ display: 'flex', flexDirection: 'column', justifyContent: 'center' }}>
        {seats}
      </div>
    </div>
  );
}

class Homepage extends React.Component {

  constructor() {
    super();  
	}

  render() {
    return (
    <div>
      <DisplayFreeSeats state={this.props.state} />
    </div>);
	}
}

class TicketToRide extends React.Component {
  constructor() {
    super();
    this.state = {
      travellers: [],
      selector: 1,
      totalseats: 50,
      reservedseats: 3,
    };
    this.bookTraveller = this.bookTraveller.bind(this);
    this.deleteTraveller = this.deleteTraveller.bind(this);
  }

  setSelector(value) {
    this.setState({ selector: value });
  }

  componentDidMount() {
    this.loadData();
  }

  loadData() {
    setTimeout(() => {
      this.setState({ travellers: initialTravellers });
    }, 500);
  }

  bookTraveller(passenger) {
    let num = this.state.travellers.length;
    let id = num + 1;

    let newTraveller = {
      id : id,
      name : passenger.name,
      phone : passenger.phone,
      bookingTime : getCurrentDateTimeString(new Date()),
      gender : parseInt(passenger.gender)
    }
    let updatedTravellers = [...this.state.travellers, newTraveller];  

    this.setState({
      travellers: updatedTravellers,
      reservedseats: this.state.reservedseats + 1,
    });
  }

  deleteTraveller(passenger) {
    let updatedTravellers = this.state.travellers.filter(traveller => traveller.id !== passenger.id);
    updatedTravellers.forEach((traveller, index) => {
      if (traveller.id > passenger.id) {
        updatedTravellers[index].id -= 1;
      }
    });  

    this.setState({
      travellers: updatedTravellers,
      reservedseats: this.state.reservedseats - 1,
    });
  }

  render() {
    let displaycomponent;
    let value = this.state.selector;

    if(value === 1){
      displaycomponent = <Homepage state= {this.state}/>;
    }else if(value === 2){
      displaycomponent = <Display travellers= {this.state.travellers} />;
    }else if(value === 3){
      displaycomponent = <Add bookTraveller={this.bookTraveller} travellers={this.state.travellers} />;
    }else if(value === 4){
      displaycomponent = <Delete deleteTraveller={this.deleteTraveller} travellers={this.state.travellers} />;
    }

    return (
      <div>
        <h1>Ticket To Ride</h1>
        <div>
            <button onClick={() => this.setSelector(1)}>Home</button>
            <button onClick={() => this.setSelector(2)}>Display</button>
            <button onClick={() => this.setSelector(3)}>Add</button>
            <button onClick={() => this.setSelector(4)}>Delete</button>
        </div>
        <div>
          {displaycomponent}
        </div>
      </div>
    );
  }
}

const element = <TicketToRide />;
ReactDOM.render(
  element,
  document.getElementById('contents')
);
