const express = require('express');
const app = express();
const csrf = require('csurf');
csrfProtection = csrf({ cookie: true });

app.get('/form', csrfProtection, function(req, res) {
    res.render('send', { csrfToken: req.csrfToken() })
})

app.post('/process', parseForm, csrfProtection, function(req, res) {
    res.send('data is being processed');
});
