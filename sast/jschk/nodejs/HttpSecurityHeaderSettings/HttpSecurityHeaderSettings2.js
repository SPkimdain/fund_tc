const express = require('express');
const app = express();//@violation
const nocache = require("nocache");
const helmet = require("helmet");

app.use(express.urlencoded({ extended: true }));
app.use(express.json());

app.use(helmet.hsts());
app.use(helmet.crossOriginEmbedderPolicy());
app.use(helmet.crossOriginOpenerPolicy());
app.use(helmet.crossOriginResourcePolicy());
app.use(helmet.frameguard());
app.use(helmet.contentSecurityPolicy());
app.use(helmet.noSniff());
app.use(helmet.permittedCrossDomainPolicies());
app.use(helmet.referrerPolicy());
//app.use(nocache());

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
