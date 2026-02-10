const express = require('express');
var router = express.Router();

function bad() {
    router.post('/login', function (req, res) {
        const id = req.body.input1;
        const pwd = req.body.input2;
        const query = 'SELECT * FROM users WHERE id=' + id + ' and pwd=' + pwd;
        const sequelize = require("sequelize");

        sequelize.query(query).then((result) => {  // @violation
            // ...
        }).catch((err) => {
            // ...
        });
    });
}

function good() {
    router.post('/login', function (req, res) {
        const id = req.body.input1;
        const pwd = req.body.input2;
        const query = 'SELECT * FROM info where Id = $1 and pwd = $2';
        const sequelize = db.sequelize;

        sequelize.query(query, {
            bind: [id, pwd]
        }).then((result) => {
            // ...
        }).catch((err) => {
            // ...
        });
    });
}
