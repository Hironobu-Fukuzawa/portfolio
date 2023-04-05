# my_portfolio

I am currently designing and implementing Graph QL APIs from scratch.
In terms of our group assignment @NUS, we are creating the C-to-C platform of home repair services.

In terms of the current group project, I can only show a partial program for this described as below (Put init data in init.mongo.js), to prevent plagiarism now.


```
db.professionals.remove({});
db.users.remove({});
db.companies.remove({});
db.skills.remove({});
db.services.remove({});

const usersDB =　[
    {
        id: 1,
        firstName: "John",
        lastName: "Doe",
        email: "john@example.com",
        phone: 123456789,
        password: "password"
    },
    {
        id: 2,
        firstName: "Jane",
        lastName: "Doe",
        email: "jane@example.com",
        phone: 987654321,
        password: "password"
    }
];

const professionalsDB =[
    {
        id: 1,
        userid: 1,
        createdAt: ISODate("2022-01-24T11:27:32.431Z"),
        company_id: "617b78a343ab0f6af47b2c5f",
        skill_ids: [
          "617b789c81a08a18e8bb50f4",
          "617b78a093b4ad2a40dc4a9f",
        ],
        service_ids: [
          "617b78b5fc3b3f1c52e17d69",
          "617b78bc036e8e97c1d364f2"
        ],
    },
    {
        id: 2,
        userid: 2,
        createdAt: ISODate("2022-01-24T11:27:32.431Z"),
        company_id : "617b78a343ab0f6af47b2c8z",
        skill_ids: [
          "617b789c81a08a18e8bb50d9",
          "617b78a093b4ad2a40dc4a8y",
        ],
        service_ids: [
          "617b78b5fc3b3f1c52e17777",
          "617b78bc036e8e97c1d36777"
        ],
    }
];

const companiesDB = [
    {
        _id: "617b78a343ab0f6af47b2c5f", // _id is manually defined in this sample data　to associate it with professional schema
        professional_id: 1,
        name: "ABC Company",
        email: "abc@example.com",
        location: "Tokyo, Japan",
        websiteUrl: "https://www.abc.com"
    },
    {
        _id: "617b78a343ab0f6af47b2c8z",
        professional_id: 2,
        name: "DEF Company",
        email: "def@example.com",
        location: "Yishun, Singapore",
        websiteUrl: "https://www.def.com",
    },
];

const skillsDB = [
    {
        _id: "617b789c81a08a18e8bb50f4", // _id is manually defined in this sample data　to associate it with professional schema
        professional_id: 1,
        name: "Carpentry",
        license: "1234567890",
        yearsOfExperience: 5,
        createdAt: ISODate("2022-01-24T11:30:00.000Z")
    },
    {
        _id: "617b78a093b4ad2a40dc4a9f", // _id is manually defined in this sample data　to associate it with professional schema
        professional_id: 1,
        name: "Plumbing",
        license: "0987654321",
        yearsOfExperience: 3,
        createdAt: ISODate("2022-01-24T11:31:00.000Z")
    },
    {
        _id: "617b789c81a08a18e8bb50d9",
        professional_id: 2,
        name: "Aircon Fix",
        license: "1234567890",
        yearsOfExperience: 5,
        createdAt: ISODate("2022-01-24T11:30:00.000Z")
    },
    {
        _id: "617b78a093b4ad2a40dc4a8y",
        professional_id: 2,
        name: "Window Servicing",
        license: "0987654321",
        yearsOfExperience: 3,
        createdAt: ISODate("2022-01-24T11:31:00.000Z")
    }
];

const servicesDB = [
    {
        _id: "617b78b5fc3b3f1c52e17d69", // _id is manually defined in this sample data　to associate it with professional schema
        id: 1,
        professional_id: 1,
        reservation_ids: ["617b78b5fc3b3f1c52e17d6a"],
        review_ids: ["617b78b5fc3b3f1c52e17d6b"],
        category: "Electrical Works",
        name: "Electrical Installation",
        description: "Install electrical wiring and outlets",
        price: 500,
        status: true,
        createdAt: ISODate("2022-01-24T11:32:00.000Z")
    },
    {
        _id: "617b78bc036e8e97c1d364f2", // _id is manually defined in this sample data　to associate it with professional schema
        id: 2,
        professional_id: 1,
        reservation_ids: ["617b78b5fc3b3f1c52e17888"],
        review_ids: ["617b78bc036e8e97c1d364f4"],
        category: "Plumbing",
        name: "Toilet Repair",
        description: "Repair clogged toilets",
        price: 200,
        status: true,
        createdAt: ISODate("2022-01-24T11:33:00.000Z")
    },
    {
        _id: "617b78b5fc3b3f1c52e17777",
        id: 3,
        professional_id: 2,
        reservation_ids: [],
        review_ids: [],
        category: "Aircon Servicing",
        name: "Aircon Cleaning",
        description: "Aircon Cleaning",
        price: 50,
        status: true,
        createdAt: ISODate("2022-01-24T11:32:00.000Z")
    },
    {
        _id: "617b78bc036e8e97c1d36777",
        id: 4,
        professional_id: 2,
        reservation_ids: [],
        review_ids: [],
        category: "Window Servicing",
        name: "Window Replacement",
        description: "Window Replacement",
        price: 1000,
        status: true,
        createdAt: ISODate("2022-01-24T11:33:00.000Z")
    }
];

const reservationsDB = [
    {
      _id: "617b78b5fc3b3f1c52e17d6a",
      service_id: 1,
      user_id: 1,
      date: new Date("2022-01-24T11:34:00.000Z"),
      times: ["10:00", "11:00", "12:00"],
    },
    {
      _id: "617b78b5fc3b3f1c52e17888",
      service_id: 2,
      user_id: 2,
      date: new Date("2022-01-24T11:35:00.000Z"),
      times: ["14:00", "15:00", "16:00"],
    },
];
  
const reviewsDB = [
    {
      _id: "617b78b5fc3b3f1c52e17d6b",
      service_id: 1,
      ratingProficiency: 4.5,
      ratingQos: 4.0,
      ratingResponsiveness: 4.5,
      comment: "Good work!",
      createdAt: new Date("2022-01-24T11:36:00.000Z"),
      overallRating: 4.3,
      image: "https://example.com/image.jpg",
    },
    {
      _id: "617b78bc036e8e97c1d364f4",
      service_id: 2,
      ratingProficiency: 3.5,
      ratingQos: 3.0,
      ratingResponsiveness: 3.5,
      comment: "Could be better.",
      createdAt: new Date("2022-01-24T11:37:00.000Z"),
      overallRating: 3.3,
    }
];

db.professionals.insertMany(professionalsDB);
db.users.insertMany(usersDB);
db.companies.insertMany(companiesDB);
db.skills.insertMany(skillsDB);
db.services.insertMany(servicesDB);

db.professionals.createIndex({ id: 1 }, { unique: true });
db.professionals.createIndex({ company_id: 1 });
db.professionals.createIndex({ skill_ids: 1 });
db.professionals.createIndex({ service_ids: 1 });
db.professionals.createIndex({ user_id: 1 });

const pf_count = db.professionals.count();
const us_count = db.users.count();
const cf_count = db.companies.count();
const sk_count = db.skills.count();
const ses_count = db.services.count();

//The _id below is just a placeholder. The below collection, in fact, has only one row and one column.
//We can denote this by any name but we call this fixedindex.
db.counters.remove({ _id: 'users' });
db.counters.remove({ _id: 'professionals' });
db.counters.remove({ _id: 'companies' });
db.counters.remove({ _id: 'skills' });
db.counters.remove({ _id: 'services' });
db.counters.insert({ _id: 'users', current: us_count });
db.counters.insert({ _id: 'professionals', current: pf_count });
db.counters.insert({ _id: 'companies', current: cf_count });
db.counters.insert({ _id: 'skills', current: sk_count });
db.counters.insert({ _id: 'services', current: ses_count });

```


