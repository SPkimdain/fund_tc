const express = require('express');
const app = express();
const nocache = require("nocache");
const helmet = require("helmet");

app.use(express.urlencoded({ extended: true }));
app.use(express.json());
app.use(helmet());
app.use(nocache());

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