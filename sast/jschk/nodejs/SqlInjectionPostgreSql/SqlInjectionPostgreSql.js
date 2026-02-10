const express = require('express');
const app = express();
const { Client } = require("pg")

const client = new Client({
    user: "사용자명",
    host: "127.0.0.1",
    database: "nodedb",
    password: "사용자비밀번호",
    port: 5432,
});


function violation1() {
    app.get('/person/:id', function(req, res) {
        const sql = 'SELECT * FROM users WHERE id=' + req.params.id;
        client.query(sql, function (err, rows) {      //@violation
            //...
        });
    });
}

function violation2() {
    app.get('/person/:id', function(req, res) {
        const id = req.params.id;
        const sql = 'SELECT * FROM users WHERE id=' + id;
        client.query(sql, function (err, rows) {    //@violation
            //...
        });
    });
}

function violation3() {
    app.get('/person/:id', function(req, res) {
        const id = req.params;
        const sql = 'SELECT * FROM users WHERE id=' + id;
        client.query(sql, function (err, rows) {    //@violation
            //...
        });
    });
}

function violation4() {
    app.get('/person/:id', function(req, res) {
        var user_id = req.param('id');
        const sql = 'SELECT * FROM users WHERE id=' + user_id;
        client.query(sql + req.params.id, function (err, rows) { //@violation
            //...
        });
    });
}

function violation5() {
    app.get('/person/:id', function(req, res) {
        const sql = 'SELECT * FROM users WHERE id=';
        client.query(sql + req.params.id, function (err, rows) { //@violation
            //...
        });
    });
}

function violation6() {
    app.get('/person/:id', function(req, res) {
        client.query('SELECT * FROM users WHERE id=' + req.params.id, function (err, rows) { //@violation
            //...
        });
    });
}

//$1을 통해 컴파일 된 쿼리문(상수)로 사용.
function good(){
    app.get('/person/:id', function(req, res) {
        const id = req.params.id;
        const sql = 'SELECT * FROM users WHERE id= $1'
        client.query(sql, id, function (err, rows) {
            //...
        });
    });
}

function good2(){
    var pg = require('./test-helper').pg
    var sql = 'SELECT 1 AS "\\\'/*", 2 AS "\\\'*/\n + process.exit(-1)] = null;\n//"'

    var client = new pg.Client()
    client.connect()
    client.query(sql, function (err, res) {
      if (err) throw err
      client.end()
    })
}
