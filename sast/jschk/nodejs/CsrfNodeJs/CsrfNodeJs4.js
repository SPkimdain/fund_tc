const express = require('express');
const app = express();
const csrf = require('csurf');
csrfProtection = csrf({ cookie: false });//@violation

app.get('/form', function(req, res) {//@violation
    res.render('send', { csrfToken: req.csrfToken() })
})

app.post('/process', parseForm, function(req, res) {//@violation
    res.send('data is being processed');
});