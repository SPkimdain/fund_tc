var express = require('express');
var router = express.Router();
const csrf = require('csurf');
const session = require("express-session");
const app = express();

const csrfProtection = csrf({
    cookie: true
});

app.use(session({
    secret: process.env.SESSION_SECRET,
    cookie: {path: '/', secure: true, httpOnly: true, sameSite: 'strict'},
    saveUninitialized: false,
    resave: false
}));

router.post('/safe', csrfProtection, function (req, res) {
    const str = req.body.input1;
    //safe
    const Upper_str = str.toUpperCase();
    return res.send({data: Upper_str});
});

router.post('/dan', function (req, res) {   //@violation
    const str = req.body.input1;
    const Upper_str = str.toUpperCase();
    return res.send({data: Upper_str});
});
module.exports = router;