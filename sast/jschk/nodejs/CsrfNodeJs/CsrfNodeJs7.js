const express = require('express');
const app = express();
const csrf = require('csurf');

app.get('/form', csrf({ cookie: true }), function(req, res) { //good
    res.render('send', { csrfToken: req.csrfToken() })
})

app.post('/process', parseForm, csrf({ cookie: true }), function(req, res) {//good
    res.send('data is being processed');
});
