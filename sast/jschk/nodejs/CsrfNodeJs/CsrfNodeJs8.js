const express = require('express');
const app = express();
app.get('/form', function(req, res) {
    res.render('send', { csrfToken: req.csrfToken() })
})

app.post('/process', parseForm, function(req, res) {
    res.send('data is being processed');
});
