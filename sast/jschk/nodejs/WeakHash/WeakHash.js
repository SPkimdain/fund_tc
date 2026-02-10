const express = require('express');
const router = express.Router();
const crypto = require("crypto");

const dan_hash_content = crypto.createHash('sha256').update(content).digest('hex'); //@violation

const randomBytes = new Uint32Array(1);
crypto.randomFillSync(randomBytes);
const safe_salt1 = randomBytes[0].toString();
const safe_hash_content1 = crypto.createHash('sha256').update(orgin_content+safe_salt1).digest('hex');

const safe_salt2 = crypto.randomBytes(4).toString('hex');
const safe_hash_content2 = crypto.createHash('sha256').update(orgin_content+safe_salt2).digest('hex');

router.post('/1D_1', function (req, res) {
    const orgin_content = req.body.content;
    const dan_hash_content = crypto.createHash('sha256').update(orgin_content).digest('hex');               //@violation
    return res.send({data: dan_hash_content});
});

router.post('/1D_2', function (req, res) {
    const orgin_content = req.body.content;
    const dan_salt = crypto.randomBytes(0).toString('hex');
    const dan_hash_content = crypto.createHash('sha224').update(orgin_content + dan_salt).digest('hex');    //@violation
    return res.send({data: dan_hash_content});
});

router.post('/1D_3', function (req, res) {
    const orgin_content = req.body.content;
    const dan_salt = crypto.randomBytes(0).toString('hex');
    const dan_hash_content = crypto.createHash('sha384').update(orgin_content + dan_salt).digest('hex');    //@violation
    return res.send({data: dan_hash_content});
});

router.post('/1D_4', function (req, res) {
    const orgin_content = req.body.content;
    const dan_hash_content = crypto.createHash('sha384').update(orgin_content + crypto.randomBytes(0.0).toString('hex')).digest('hex');    //@violation
    return res.send({data: dan_hash_content});
});

router.post('/1S_1', function (req, res) {
    const orgin_content = req.body.content;
    const randomBytes = new Uint32Array(1);
    crypto.randomFillSync(randomBytes);
    const safe_salt = randomBytes[0].toString();
    const safe_hash_content = crypto.createHash('sha256').update(orgin_content + safe_salt).digest('hex');
    return res.send({data: safe_hash_content});
});

router.post('/1S_2', function (req, res) {
    const orgin_content = req.body.content;
    const safe_salt = process.env.SALT;
    const safe_hash_content = crypto.createHash('sha256').update(orgin_content + safe_salt).digest('hex');
    return res.send({data:safe_hash_content});
});

module.exports = router;