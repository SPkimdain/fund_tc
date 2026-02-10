const express = require('express');
const express2 = require('express');
const app = express();
const app2 = express();
const app3 = express2();
const app4 = express2();

const helmet = require("helmet");
const helmet2 = require('helmet');

app.use(express.urlencoded({ extended: true }));
app.use(express.json());
app.use(helmet());
app.use(helmet.noCache());

app2.use(express.urlencoded({ extended: true }));
app2.use(express.json());
app2.use(helmet());
app2.use(helmet.noCache());

app3.use(express2.urlencoded({ extended: true }));
app3.use(express2.json());
app3.use(helmet());
app3.use(helmet.noCache());

app4.use(express2.urlencoded({ extended: true }));
app4.use(express2.json());
app4.use(helmet2());
app4.use(helmet2.noCache());

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
  console.log('running server at Port:4000');
});