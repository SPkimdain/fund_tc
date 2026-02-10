var express = require('express');
var router = express.Router();

//취약한 암호화 알고리즘 사용
const crypto = require("crypto");
const bcrypt = require('bcrypt');
const mysql = require("mysql");
const md5 = require('md5');

console.log(md5('password')); // @violation

bcrypt.hash("password", 13, function(err, hash) {
    console.log(hash);
});

const cipher = crypto.createCipheriv('des-ede3', Key, '');  // @violation
const cipher = crypto.createCipheriv('aes-256-cbc', key, iv);

function encrypt3DES(algo, data, key) {
    const cipher = crypto.createCipheriv('des-ede3', md5Key, '');       //@violation

    let encrypted = cipher.update(data, 'utf8', 'base64');
    encrypted += cipher.final('base64');
    return encrypted;
}

function encryptAES(text, ENCRYPTION_KEY, IV_LENGTH) {
    let iv = crypto.randomBytes(IV_LENGTH);
    let cipher = crypto.createCipheriv('aes-256-cbc', Buffer.from(ENCRYPTION_KEY), iv);
    let encrypted = cipher.update(text);
    encrypted = Buffer.concat([encrypted, cipher.final()]);
    return iv.toString('hex') + ':' + encrypted.toString('hex');
}

function decryptAES(text, ENCRYPTION_KEY) {
    let textParts = text.split(':');
    let iv = Buffer.from(textParts.shift(), 'hex');
    let encryptedText = Buffer.from(textParts.join(':'), 'hex');
    let decipher = crypto.createDecipheriv('aes-256-cbc', Buffer.from(ENCRYPTION_KEY), iv);
    let decrypted = decipher.update(encryptedText);
    decrypted = Buffer.concat([decrypted, decipher.final()]);
    return decrypted.toString();
}

function makeMd5(text) {
    return crypto.createHash('md5').update(text).digest('hex');       //@violation
}

function makeSha1(text) {
    return crypto.createHash('sha1').update(text).digest('hex');       //@violation
}
router.post('/1D_1', function (req, res) {
    const content_origin = req.body.content;
    const des_enc = makeSha1(content_origin);
    return res.send(des_enc);
});

router.post('/1D_2', function (req, res) {
    const content_origin = req.body.content;
    const des_enc = makeMd5(content_origin);
    return res.send(des_enc);
});

router.post('/1D_3', function (req, res) {
    const content_origin = req.body.content;
    const key = crypto.randomBytes(32);
    const iv = crypto.randomBytes(16);

    const des_enc = encrypt3DES('md5',content_origin, key)
    const des_dec =decrypt3DES('md5',des_enc,key);
    return res.send(des_dec);
});

router.post('/1D_4', function (req, res) {
    const content_origin = req.body.content;
    const key = crypto.randomBytes(32);
    const iv = crypto.randomBytes(16);

    const des_enc = encrypt3DES('sha224',content_origin, key)
    const des_dec =decrypt3DES('sha224',des_enc,key);
    return res.send(des_dec);
});
router.post('/1D_5', function (req, res) {
    const content_origin = req.body.content;
    const key = crypto.randomBytes(32);
    const iv = crypto.randomBytes(16);

    const mKey = crypto.createHash('sha256').update(key).digest("hex").substr(0, 24);
    const cipher = crypto.createCipheriv('rc2', mKey, '');       //@violation

    let encrypted = cipher.update(content_origin, 'utf8', 'base64');
    encrypted += cipher.final('base64');
    return res.send(encrypted);
});

function encryptAES(algo, text, ENCRYPTION_KEY, IV_LENGTH) {
    let iv = crypto.randomBytes(IV_LENGTH);
    let cipher = crypto.createCipheriv(algo, Buffer.from(ENCRYPTION_KEY), iv);
    let encrypted = cipher.update(text);
    encrypted = Buffer.concat([encrypted, cipher.final()]);
    return iv.toString('hex') + ':' + encrypted.toString('hex');
}

function decryptAES(algo, text, ENCRYPTION_KEY) {
    let textParts = text.split(':');
    let iv = Buffer.from(textParts.shift(), 'hex');
    let encryptedText = Buffer.from(textParts.join(':'), 'hex');
    let decipher = crypto.createDecipheriv(algo, Buffer.from(ENCRYPTION_KEY), iv);
    let decrypted = decipher.update(encryptedText);
    decrypted = Buffer.concat([decrypted, decipher.final()]);
    return decrypted.toString();
}
router.post('/1S_1', function (req, res) {
    const content_origin = req.body.content;
    const ENCRYPTION_KEY =
        process.env.ENCRYPTION_KEY || 'abcdefghijklmnop'.repeat(2) // Must be 256 bits (32 characters)
    const IV_LENGTH = 16 // For AES, this is always 16
    const aes_enc = encryptAES('aes-192-cfb8',content_origin, ENCRYPTION_KEY, IV_LENGTH);
    const aes_dec = decryptAES('aes-192-cfb8',aes_enc, ENCRYPTION_KEY);
    return res.send(aes_enc);
});

router.post('/1S_2', function (req, res) {
    const content_origin = req.body.content;
    const ENCRYPTION_KEY =
        process.env.ENCRYPTION_KEY || 'abcdefghijklmnop'.repeat(2) // Must be 256 bits (32 characters)
    const IV_LENGTH = 16 // For AES, this is always 16
    const aes_enc = encryptAES('aes-256-xts',content_origin, ENCRYPTION_KEY, IV_LENGTH);
    const aes_dec = decryptAES('aes-256-xts',aes_enc, ENCRYPTION_KEY);
    return res.send(aes_enc);
});
router.post('/1S_3', function (req, res) {
    const content_origin = req.body.content;

    bcrypt.hash(content_origin, 0).then(hash =>{
        return res.send(hash);
    }).catch(err =>{
        return res.status(500).send(err.message);
    });
});

child.descAt(pos-offset-child.border);
this.widget.type.destroy(this.dom);
super.destroy(tmp);

module.exports = router;

