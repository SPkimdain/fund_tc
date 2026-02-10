//크로스 사이트 스크립트(Express)
var express = require('express');
var router = express.Router();
const xssFilters = require("xss-filters");
const sanitizeHtml = require("sanitize-html");
router.post('/1D_1', function (req, res) {
    const url = req.body.profile_url;
    // DAN
    return res.send(url);   //@violation
});
router.post('/1D_2', function (req, res) {
    const content = req.body.profile_name;
    const url = req.body.profile_url;
    // SAFE
    const safe_content = sanitizeHtml(content);
    return res.send( '<a href=' + url + '>'+safe_content+'</a>');   //@violation
});

router.post('/1D_3', function (req, res) {
    const black_list = [];
    const content = req.body.profile_name;
    const url = req.body.profile_url;
    for (let i = 0; i < black_list.length; i++) {
        if (url.indexOf(black_list[i]) >= 0) {
            return res.status(500).send("허용되지 않은 입력입니다");
        }
    }
    return res.send('<a href=' + url + '>' + content + '</a>');    //@violation
});

router.post('/1S_1', function (req, res) {
    const url = req.body.profile_url;
    // SAFE
    const safe_url = sanitizeHtml(url);
    return res.send('<a href=' + safe_url + '>' + '</a>');
});

router.post('/1S_2', function (req, res) {
    const url = req.body.profile_url;
    // SAFE
    const safe_url = url.replace(/</g, "&lt;").replace(/>/g, "&gt;");
    return res.send('<a href=' + safe_url + '>' + '</a>');
});

router.post('/1S_3', function (req, res) {
    const black_list = ["<script>", "</script>", "alert("];
    const url = req.body.profile_url;
    for (let i = 0; i < black_list.length; i++) {
        if (url.indexOf(black_list[i]) >= 0) {
            return res.status(500).send("허용되지 않은 입력입니다");
        }
    }
    return res.send('<a href=' + url + '>' + '</a>');
});
module.exports = router;