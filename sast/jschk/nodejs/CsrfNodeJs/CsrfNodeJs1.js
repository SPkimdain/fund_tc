const express = require('express');
const expr = require('express');
const app = express();
const app2 = express();
const app3 = expr();

const csrf = require('csurf');
const csrf2 = require('csurf');

csrfProtection = csrf({ temp: false});//@violation
csrfProtection2 = csrf({ cookie: false, temp: false});//@violation
csrfDepender = csrf({cookie:true});
csrfViolation = csrf({cookie:false});//@violation

app.get('/form', function(req, res) {//@violation
    res.render('send', {})
})

app.get('/form',csrfProtection ,function(req, res) {
    res.render('send', {})
})

app.get('/form',csrf({ temp: false}) ,function(req, res) {//@violation
    res.render('send', {})
})

app.post('/process', parseForm, function(req, res) {//@violation
    res.send('data is being processed');
});

app2.post('/process', function(req, res) {//@violation
    res.send('data is being processed');
});

app2.get('/process', csrf({cookie: true}), function(req, res) {//safe
    res.send('data is being processed');
});

app2.get('/process', csrf({cookie: false}), function(req, res) {//@violation
    res.send('data is being processed');
});

app3.get('/process', csrfDepender, function(req, res) {//safe
    res.send('data is being processed');
});

app3.get('/process', csrfViolation, function(req, res) {//csrfViolation 선언에서 걸림
    res.send('data is being processed');
});