"use strict";

function _typeof(obj) { "@babel/helpers - typeof"; return _typeof = "function" == typeof Symbol && "symbol" == typeof Symbol.iterator ? function (obj) { return typeof obj; } : function (obj) { return obj && "function" == typeof Symbol && obj.constructor === Symbol && obj !== Symbol.prototype ? "symbol" : typeof obj; }, _typeof(obj); }
function _toConsumableArray(arr) { return _arrayWithoutHoles(arr) || _iterableToArray(arr) || _unsupportedIterableToArray(arr) || _nonIterableSpread(); }
function _nonIterableSpread() { throw new TypeError("Invalid attempt to spread non-iterable instance.\nIn order to be iterable, non-array objects must have a [Symbol.iterator]() method."); }
function _unsupportedIterableToArray(o, minLen) { if (!o) return; if (typeof o === "string") return _arrayLikeToArray(o, minLen); var n = Object.prototype.toString.call(o).slice(8, -1); if (n === "Object" && o.constructor) n = o.constructor.name; if (n === "Map" || n === "Set") return Array.from(o); if (n === "Arguments" || /^(?:Ui|I)nt(?:8|16|32)(?:Clamped)?Array$/.test(n)) return _arrayLikeToArray(o, minLen); }
function _iterableToArray(iter) { if (typeof Symbol !== "undefined" && iter[Symbol.iterator] != null || iter["@@iterator"] != null) return Array.from(iter); }
function _arrayWithoutHoles(arr) { if (Array.isArray(arr)) return _arrayLikeToArray(arr); }
function _arrayLikeToArray(arr, len) { if (len == null || len > arr.length) len = arr.length; for (var i = 0, arr2 = new Array(len); i < len; i++) arr2[i] = arr[i]; return arr2; }
function _classCallCheck(instance, Constructor) { if (!(instance instanceof Constructor)) { throw new TypeError("Cannot call a class as a function"); } }
function _defineProperties(target, props) { for (var i = 0; i < props.length; i++) { var descriptor = props[i]; descriptor.enumerable = descriptor.enumerable || false; descriptor.configurable = true; if ("value" in descriptor) descriptor.writable = true; Object.defineProperty(target, _toPropertyKey(descriptor.key), descriptor); } }
function _createClass(Constructor, protoProps, staticProps) { if (protoProps) _defineProperties(Constructor.prototype, protoProps); if (staticProps) _defineProperties(Constructor, staticProps); Object.defineProperty(Constructor, "prototype", { writable: false }); return Constructor; }
function _toPropertyKey(arg) { var key = _toPrimitive(arg, "string"); return _typeof(key) === "symbol" ? key : String(key); }
function _toPrimitive(input, hint) { if (_typeof(input) !== "object" || input === null) return input; var prim = input[Symbol.toPrimitive]; if (prim !== undefined) { var res = prim.call(input, hint || "default"); if (_typeof(res) !== "object") return res; throw new TypeError("@@toPrimitive must return a primitive value."); } return (hint === "string" ? String : Number)(input); }
function _inherits(subClass, superClass) { if (typeof superClass !== "function" && superClass !== null) { throw new TypeError("Super expression must either be null or a function"); } subClass.prototype = Object.create(superClass && superClass.prototype, { constructor: { value: subClass, writable: true, configurable: true } }); Object.defineProperty(subClass, "prototype", { writable: false }); if (superClass) _setPrototypeOf(subClass, superClass); }
function _setPrototypeOf(o, p) { _setPrototypeOf = Object.setPrototypeOf ? Object.setPrototypeOf.bind() : function _setPrototypeOf(o, p) { o.__proto__ = p; return o; }; return _setPrototypeOf(o, p); }
function _createSuper(Derived) { var hasNativeReflectConstruct = _isNativeReflectConstruct(); return function _createSuperInternal() { var Super = _getPrototypeOf(Derived), result; if (hasNativeReflectConstruct) { var NewTarget = _getPrototypeOf(this).constructor; result = Reflect.construct(Super, arguments, NewTarget); } else { result = Super.apply(this, arguments); } return _possibleConstructorReturn(this, result); }; }
function _possibleConstructorReturn(self, call) { if (call && (_typeof(call) === "object" || typeof call === "function")) { return call; } else if (call !== void 0) { throw new TypeError("Derived constructors may only return object or undefined"); } return _assertThisInitialized(self); }
function _assertThisInitialized(self) { if (self === void 0) { throw new ReferenceError("this hasn't been initialised - super() hasn't been called"); } return self; }
function _isNativeReflectConstruct() { if (typeof Reflect === "undefined" || !Reflect.construct) return false; if (Reflect.construct.sham) return false; if (typeof Proxy === "function") return true; try { Boolean.prototype.valueOf.call(Reflect.construct(Boolean, [], function () {})); return true; } catch (e) { return false; } }
function _getPrototypeOf(o) { _getPrototypeOf = Object.setPrototypeOf ? Object.getPrototypeOf.bind() : function _getPrototypeOf(o) { return o.__proto__ || Object.getPrototypeOf(o); }; return _getPrototypeOf(o); }
// Student ID: A0255967J
// Student Name: Hironobu Fukuzawa

var initialTravellers = [{
  id: 1,
  name: 'Jack',
  phone: 88885555,
  bookingTime: getCurrentDateTimeString(new Date()),
  gender: 0
}, {
  id: 2,
  name: 'Rose',
  phone: 88884444,
  bookingTime: getCurrentDateTimeString(new Date()),
  gender: 1
}, {
  id: 3,
  name: 'Hisoka',
  phone: 99999999,
  bookingTime: getCurrentDateTimeString(new Date()),
  gender: 2
}];
function getCurrentDateTimeString(now) {
  var year = now.getFullYear();
  var month = ('0' + (now.getMonth() + 1)).slice(-2);
  var day = ('0' + now.getDate()).slice(-2);
  var hours = ('0' + now.getHours()).slice(-2);
  var minutes = ('0' + now.getMinutes()).slice(-2);
  return "".concat(year, "-").concat(month, "-").concat(day, "-").concat(hours).concat(minutes);
}
function TravellerRow(props) {
  var traveller = props.traveller;
  var gender;
  if (traveller.gender === 0) {
    gender = 'Male';
  } else if (traveller.gender === 1) {
    gender = 'Female';
  } else if (traveller.gender === 2) {
    gender = 'Others';
  }
  return /*#__PURE__*/React.createElement("tr", null, /*#__PURE__*/React.createElement("td", null, traveller.id), /*#__PURE__*/React.createElement("td", null, traveller.name), /*#__PURE__*/React.createElement("td", null, traveller.phone), /*#__PURE__*/React.createElement("td", null, traveller.bookingTime.toString()), /*#__PURE__*/React.createElement("td", null, gender));
}
function Display(props) {
  var travellers = props.travellers;
  return /*#__PURE__*/React.createElement("table", {
    className: "bordered-table"
  }, /*#__PURE__*/React.createElement("thead", null, /*#__PURE__*/React.createElement("tr", null, /*#__PURE__*/React.createElement("th", null, "ID"), /*#__PURE__*/React.createElement("th", null, "Name"), /*#__PURE__*/React.createElement("th", null, "Phone"), /*#__PURE__*/React.createElement("th", null, "Booking Time"), /*#__PURE__*/React.createElement("th", null, "Gender"))), /*#__PURE__*/React.createElement("tbody", null, travellers.map(function (traveller) {
    return /*#__PURE__*/React.createElement(TravellerRow, {
      key: traveller.id,
      traveller: traveller
    });
  })));
}
var Add = /*#__PURE__*/function (_React$Component) {
  _inherits(Add, _React$Component);
  var _super = _createSuper(Add);
  function Add() {
    var _this;
    _classCallCheck(this, Add);
    _this = _super.call(this);
    _this.handleSubmit = _this.handleSubmit.bind(_assertThisInitialized(_this));
    return _this;
  }
  _createClass(Add, [{
    key: "handleSubmit",
    value: function handleSubmit(e) {
      e.preventDefault();
      var traveller = {
        name: e.target.elements.travellername.value,
        phone: e.target.elements.phone.value,
        gender: e.target.elements.gender.value
      };
      this.props.bookTraveller(traveller);
    }
  }, {
    key: "render",
    value: function render() {
      var _this$props$traveller;
      return /*#__PURE__*/React.createElement("form", {
        name: "addTraveller",
        onSubmit: this.handleSubmit
      }, ((_this$props$traveller = this.props.travellers) === null || _this$props$traveller === void 0 ? void 0 : _this$props$traveller.length) < 50 ? /*#__PURE__*/React.createElement(React.Fragment, null, /*#__PURE__*/React.createElement("input", {
        type: "text",
        name: "travellername",
        placeholder: "Name"
      }), /*#__PURE__*/React.createElement("input", {
        type: "text",
        name: "phone",
        placeholder: "Phone"
      }), /*#__PURE__*/React.createElement("select", {
        name: "gender"
      }, /*#__PURE__*/React.createElement("option", {
        value: "0"
      }, "Male"), /*#__PURE__*/React.createElement("option", {
        value: "1"
      }, "Female"), /*#__PURE__*/React.createElement("option", {
        value: "2"
      }, "Others")), /*#__PURE__*/React.createElement("button", null, "Add")) : /*#__PURE__*/React.createElement("div", {
        style: {
          color: 'red'
        }
      }, "The maximum number of seats has already been booked."));
    }
  }]);
  return Add;
}(React.Component);
var Delete = /*#__PURE__*/function (_React$Component2) {
  _inherits(Delete, _React$Component2);
  var _super2 = _createSuper(Delete);
  function Delete() {
    var _this2;
    _classCallCheck(this, Delete);
    _this2 = _super2.call(this);
    _this2.handleSubmit = _this2.handleSubmit.bind(_assertThisInitialized(_this2));
    return _this2;
  }
  _createClass(Delete, [{
    key: "handleSubmit",
    value: function handleSubmit(e) {
      e.preventDefault();
      var id = e.target.elements.travellername.value;
      var selectedTraveller = this.props.travellers.find(function (traveller) {
        return traveller.id === parseInt(id);
      });
      if (selectedTraveller) {
        this.props.deleteTraveller(selectedTraveller);
      }
    }
  }, {
    key: "render",
    value: function render() {
      var _this$props$traveller2;
      return /*#__PURE__*/React.createElement("form", {
        name: "deleteTraveller",
        onSubmit: this.handleSubmit
      }, ((_this$props$traveller2 = this.props.travellers) === null || _this$props$traveller2 === void 0 ? void 0 : _this$props$traveller2.length) > 0 ? /*#__PURE__*/React.createElement(React.Fragment, null, /*#__PURE__*/React.createElement("select", {
        name: "travellername"
      }, this.props.travellers.map(function (traveller) {
        return /*#__PURE__*/React.createElement("option", {
          key: traveller.id,
          value: traveller.id
        }, traveller.name);
      })), /*#__PURE__*/React.createElement("button", null, "Delete")) : /*#__PURE__*/React.createElement("div", {
        style: {
          color: 'red'
        }
      }, "No travellers found."));
    }
  }]);
  return Delete;
}(React.Component);
function DisplayFreeSeats(props) {
  var reservedseats = props.state.reservedseats;
  var totalseats = props.state.totalseats;
  var freeSeats = totalseats - reservedseats;
  var reservedSeatsArray = Array.from({
    length: reservedseats
  }, function (_, index) {
    return index;
  });
  var freeSeatsArray = Array.from({
    length: freeSeats
  }, function (_, index) {
    return index;
  });
  var rows = Math.ceil(totalseats / 10);
  var seats = [];
  for (var i = 0; i < rows; i++) {
    var row = [];
    var oneline = /*#__PURE__*/React.createElement("div", {
      key: i,
      style: {
        display: 'flex',
        flexDirection: 'row'
      }
    }, row);
    for (var j = 0; j < 10; j++) {
      var seatNumber = i * 10 + j;
      var margin = j === 4 ? '5px 15px 5px 5px' : j === 5 ? '5px 5px 5px 15px' : '5px';
      var divEmpty = /*#__PURE__*/React.createElement("div", {
        key: seatNumber,
        style: {
          backgroundColor: 'gray',
          height: '40px',
          width: '40px',
          margin: margin,
          border: '1px solid black'
        }
      });
      var divReserved = /*#__PURE__*/React.createElement("div", {
        key: seatNumber,
        style: {
          backgroundColor: 'white',
          height: '40px',
          width: '40px',
          margin: margin,
          border: '1px solid black'
        }
      });
      if (reservedSeatsArray.includes(seatNumber)) {
        row.push(divEmpty);
      } else {
        row.push(divReserved);
      }
    }
    seats.push(oneline);
  }
  return /*#__PURE__*/React.createElement("div", null, /*#__PURE__*/React.createElement("h2", null, "AVAILABLE SEATS: ", freeSeats, " SEATS FREE Out Of ", totalseats, " Total"), /*#__PURE__*/React.createElement("div", {
    style: {
      display: 'flex',
      flexDirection: 'column',
      justifyContent: 'center'
    }
  }, seats));
}
var Homepage = /*#__PURE__*/function (_React$Component3) {
  _inherits(Homepage, _React$Component3);
  var _super3 = _createSuper(Homepage);
  function Homepage() {
    _classCallCheck(this, Homepage);
    return _super3.call(this);
  }
  _createClass(Homepage, [{
    key: "render",
    value: function render() {
      return /*#__PURE__*/React.createElement("div", null, /*#__PURE__*/React.createElement(DisplayFreeSeats, {
        state: this.props.state
      }));
    }
  }]);
  return Homepage;
}(React.Component);
var TicketToRide = /*#__PURE__*/function (_React$Component4) {
  _inherits(TicketToRide, _React$Component4);
  var _super4 = _createSuper(TicketToRide);
  function TicketToRide() {
    var _this3;
    _classCallCheck(this, TicketToRide);
    _this3 = _super4.call(this);
    _this3.state = {
      travellers: [],
      selector: 1,
      totalseats: 50,
      reservedseats: 3
    };
    _this3.bookTraveller = _this3.bookTraveller.bind(_assertThisInitialized(_this3));
    _this3.deleteTraveller = _this3.deleteTraveller.bind(_assertThisInitialized(_this3));
    return _this3;
  }
  _createClass(TicketToRide, [{
    key: "setSelector",
    value: function setSelector(value) {
      this.setState({
        selector: value
      });
    }
  }, {
    key: "componentDidMount",
    value: function componentDidMount() {
      this.loadData();
    }
  }, {
    key: "loadData",
    value: function loadData() {
      var _this4 = this;
      setTimeout(function () {
        _this4.setState({
          travellers: initialTravellers
        });
      }, 500);
    }
  }, {
    key: "bookTraveller",
    value: function bookTraveller(passenger) {
      var num = this.state.travellers.length;
      var id = num + 1;
      var newTraveller = {
        id: id,
        name: passenger.name,
        phone: passenger.phone,
        bookingTime: getCurrentDateTimeString(new Date()),
        gender: parseInt(passenger.gender)
      };
      var updatedTravellers = [].concat(_toConsumableArray(this.state.travellers), [newTraveller]);
      this.setState({
        travellers: updatedTravellers,
        reservedseats: this.state.reservedseats + 1
      });
    }
  }, {
    key: "deleteTraveller",
    value: function deleteTraveller(passenger) {
      var updatedTravellers = this.state.travellers.filter(function (traveller) {
        return traveller.id !== passenger.id;
      });
      updatedTravellers.forEach(function (traveller, index) {
        if (traveller.id > passenger.id) {
          updatedTravellers[index].id -= 1;
        }
      });
      this.setState({
        travellers: updatedTravellers,
        reservedseats: this.state.reservedseats - 1
      });
    }
  }, {
    key: "render",
    value: function render() {
      var _this5 = this;
      var displaycomponent;
      var value = this.state.selector;
      if (value === 1) {
        displaycomponent = /*#__PURE__*/React.createElement(Homepage, {
          state: this.state
        });
      } else if (value === 2) {
        displaycomponent = /*#__PURE__*/React.createElement(Display, {
          travellers: this.state.travellers
        });
      } else if (value === 3) {
        displaycomponent = /*#__PURE__*/React.createElement(Add, {
          bookTraveller: this.bookTraveller,
          travellers: this.state.travellers
        });
      } else if (value === 4) {
        displaycomponent = /*#__PURE__*/React.createElement(Delete, {
          deleteTraveller: this.deleteTraveller,
          travellers: this.state.travellers
        });
      }
      return /*#__PURE__*/React.createElement("div", null, /*#__PURE__*/React.createElement("h1", null, "Ticket To Ride"), /*#__PURE__*/React.createElement("div", null, /*#__PURE__*/React.createElement("button", {
        onClick: function onClick() {
          return _this5.setSelector(1);
        }
      }, "Home"), /*#__PURE__*/React.createElement("button", {
        onClick: function onClick() {
          return _this5.setSelector(2);
        }
      }, "Display"), /*#__PURE__*/React.createElement("button", {
        onClick: function onClick() {
          return _this5.setSelector(3);
        }
      }, "Add"), /*#__PURE__*/React.createElement("button", {
        onClick: function onClick() {
          return _this5.setSelector(4);
        }
      }, "Delete")), /*#__PURE__*/React.createElement("div", null, displaycomponent));
    }
  }]);
  return TicketToRide;
}(React.Component);
var element = /*#__PURE__*/React.createElement(TicketToRide, null);
ReactDOM.render(element, document.getElementById('contents'));