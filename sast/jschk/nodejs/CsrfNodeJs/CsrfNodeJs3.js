const express = require('express');
const app = express();
const csrf = require('csurf');

app.get('/form', function(req, res) {//@violation
    res.render('send', {})
})

app.post('/process', parseForm, function(req, res) {//@violation
    res.send('data is being processed');
});
