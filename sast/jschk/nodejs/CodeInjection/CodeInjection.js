var express = require('express')
const crypto = require('crypto');
var app = express()
var router = express.Router();

function violation1() {
    app.post('/profile', function (req, res) {
        const data = req.query;
        const evaldata = eval(data);//@violation
        const funcdata = new Function(data);//@violation
    });
}

function violation2() {
    app.post('/profile', function (req, res) {
        const data = req.query;
        const cleanData = req.query.replace(reg, "");

        const evalData = eval(data);//@violation
        const evalData2 = eval(req.query);//@violation
        const evalCleanData = eval(cleanData);
        const evalCleanData2 = eval(req.query.replace(reg, ""));
        const funcData = new Function(data);//@violation
    });
}

function check_input(msg) {
    const white_list = /^[0-9a-zA-Z+\-*/]+$/;
    return !!msg.match(white_list);
}

router.post('/safe', function (req, res) {
    const msg = req.body.content;
    //safe
    if (check_input(msg)) {
        return res.send({data: eval(msg)})  /* SAFE */
    } else {
        return res.send({data: "잘못된 입력입니다"});
    }
});

router.post('/dan', function (req, res) {
    const msg = req.body.content;
    //dan
    const data = eval(msg); // @violation
    return res.send({data: data});
});