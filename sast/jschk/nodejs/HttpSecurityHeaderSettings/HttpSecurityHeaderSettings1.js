const express = require('express');
const express2 = require('express');

const app = express(); //@violation
const app2 = express();//@violation
const app3 = express2();//@violation
const app4 = express2();//@violation

const nocache = require("nocache");
const helmet = require("helmet");

app.use(express.urlencoded({ extended: true }));
app.use(express.json());
app.use(helmet());

app2.use(express.urlencoded({ extended: true }));
app2.use(express.json());
app2.use(helmet());
//app2.use(nocache());

app3.use(express.urlencoded({ extended: true }));
app3.use(express.json());
//app3.use(helmet.hsts());
app3.use(helmet.crossOriginEmbedderPolicy());
app3.use(helmet.crossOriginOpenerPolicy());
app3.use(helmet.crossOriginResourcePolicy());
app3.use(helmet.frameguard());
app3.use(helmet.contentSecurityPolicy());
app3.use(helmet.noSniff());
app3.use(helmet.permittedCrossDomainPolicies());
app3.use(helmet.referrerPolicy());

app4.use(express.urlencoded({ extended: true }));
app4.use(express.json());
app4.use(helmet.hsts());
app4.use(helmet.crossOriginEmbedderPolicy());
app4.use(helmet.crossOriginOpenerPolicy());
app4.use(helmet.crossOriginResourcePolicy());
app4.use(helmet.frameguard());
app4.use(helmet.contentSecurityPolicy());
app4.use(helmet.noSniff());
app4.use(helmet.permittedCrossDomainPolicies());
app4.use(helmet.referrerPolicy());
app4.use(nocache());

app.get('/', (req, res) => {
  res.send(`
  <form action="/" method="post">
    <input type="submit" name="position" value="input1">
    <input type="submit" name="position" value="input2">
  </form>
  `);
});

app.post('/', (req, res) => {
  console.log(req.body);
});

app.listen(3000, () => {
  console.log('running server at Port:3000');
});

app2.get('/', (req, res) => {
  res.send(`
  <form action="/" method="post">
    <input type="submit" name="position" value="input1">
    <input type="submit" name="position" value="input2">
  </form>
  `);
});

app2.post('/', (req, res) => {
  console.log(req.body);
});

app2.listen(4000, () => {
  console.log('running server at Port:4000');
});

app3.get('/', (req, res) => {
  res.send(`
  <form action="/" method="post">
    <input type="submit" name="position" value="input1">
    <input type="submit" name="position" value="input2">
  </form>
  `);
});

app3.post('/', (req, res) => {
  console.log(req.body);
});

app3.listen(5000, () => {
  console.log('running server at Port:5000');
});
