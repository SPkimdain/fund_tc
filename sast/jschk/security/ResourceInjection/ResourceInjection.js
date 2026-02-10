const express = require('express');
var router = express.Router();
const io = require("socket.io-client")

router.post('/Resource', function (req, res) {
    try {
        const socket = io(req.body.content);    // @violation
    } catch (e) {
        return res.send("[error]");
    }
});

router.post('/Resource_S1', function (req, res) {
    const whitelist = ["http://127.0.0.1:", "localhost:"];

    if (whitelist.indexOf(req.body.content) < 0) {
        return res.send("url ERROR");
    }

    try {
        const socket = io(req.body.content);
    } catch (e) {
        return res.send("[error]");
    }
});


router.post('/Resource_S2', function (req, res) {
    const whitelist = ["http://127.0.0.1:", "localhost:"];
    var content = req.body.content;

    if (whitelist.indexOf(content) < 0) {
        return res.send("url ERROR");
    }

    try {
        const socket = io(content);
    } catch (e) {
        return res.send("[error]");
    }
});

router.post('/Resource_S3', function (req, res) {
    const whitelist = ["http://127.0.0.1:", "localhost:"];

    whitelist.indexOf(req.body.content);

    const socket = io(req.body.content);
});
