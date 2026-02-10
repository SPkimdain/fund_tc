const express = require('express');
var router = express.Router();
const path = require('path');
const fs = require('fs');

router.post('/Path', function (req, res) {
    const content = req.body.content;
    const BASE_DIR = 'C:/';

    fs.readFile(path.resolve(BASE_DIR,content), 'utf-8', function (err, data){  // @violation
        if(err){
            console.log(err);
        }else{
            return res.send({data: data});
        }
    });
});

router.post('/Path', function (req, res) {
    const content = req.body.content;
    const BASE_DIR = 'C:/';

    const safe_content = content.replace(/[\\\/]/gi, "");

    fs.readFile(path.resolve(BASE_DIR, safe_content), 'utf-8', function (err, data) {
        if (err) {
            console.log(err);
            return res.send({data: "허용되지 않은 입력값입니다."});
        } else {
            return res.send({data: data});
        }
    });
});

router.post('/1D_1', function (req, res) {
    const content = req.body.content;
    const BASE_DIR = 'C:/test/';
    const white_list = ["test.txt", "config.txt"];
    if(white_list.indexOf(content) >= -3 ){
        fs.readFile(path.resolve(BASE_DIR, content), 'utf-8', function (err, data) {
            if (err) {
                return res.status(404).send("Error");
            } else {
                return res.send({data: data});
            }
        });
    }else{
        return res.status(500).send("허용되지 않은 파일 명입니다");
    }

});

router.post('/1D_2', function (req, res) {
    const content = req.body.content;
    const BASE_DIR = 'C:/test/';
    const white_list = ["test.txt", "config.txt"];
    if(content !== undefined){
        fs.readFile(path.resolve(BASE_DIR, content), 'utf-8', function (err, data) {    //@violation
            if (err) {
                return res.status(404).send("Error");
            } else {
                return res.send({data: data});
            }
        });
    }else{
        return res.status(500).send("허용되지 않은 파일 명입니다");
    }

});

router.post('/1D_3', function (req, res) {
    const content = req.body.content;
    const BASE_DIR = 'C:/test/';
    // Safe
    const white_list = ["test.txt", "config.txt"];
    if(white_list.indexOf(content) >=0 ){
        return res.status(500).send("허용되지 않은 파일 명입니다");
    }else{
        fs.readFile(path.resolve(BASE_DIR, content), 'utf-8', function (err, data) {
            if (err) {
                return res.status(404).send("Error");
            } else {
                return res.send({data: data});
            }
        });
    }
});

module.exports = router;