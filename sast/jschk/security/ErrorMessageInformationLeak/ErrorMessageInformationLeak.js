var express = require('express');
var router = express.Router();
const fs = require('fs');

router.post('/dan', function (req, res) {
    fs.readFile("C:/test1.txt", 'utf-8', function (err, data) {
        if (err) {
            return res.status(500).send(err);   // @violation
        }
        return res.send(data);
    });
});

router.post('/dan', function (req, res) {
    fs.readFile("C:/test/test1.txt", 'utf-8', function (err, data) {
        if (err) {
            return res.status(500).send({message: "파일이 없습니다"});
        }
        return res.send(data);
    });
});

router.post('/dan', function (req, res) {
    fs.readFile("C:/test/test1.txt", 'utf-8', function (err, data) {
        const er = new Error("error")
        return res.send(data);
    });
});
router.post('/dan1', function (req, res) {
    fs.readFile("C:/test/test1.txt", 'utf-8', function (err, data) {
        if (err) {
            return res.status(500).send("["+err.message+"]");     //@violation
        }
        return res.send(data);
    });
});

router.post('/dan2', function (req, res) {
    fs.readFile("C:/test/test1.txt", 'utf-8', function (err, data) {
        if (err) {
            return res.status(500).send("error/500", {message: err});   //@violation
        }
        return res.send(data);
    });
});
router.post('/safe', function (req, res) {
    //safe
    fs.readFile("C:/test/test1.txt", 'utf-8', function (err, data) {
        if (err) {
            return res.render('Error/500', {message: "파일이 없습니다"});
        }
        return res.send(data);
    });
});

router.post('/', function (req, res) {
    const user_id = req.body.id;
    const user_pwd = req.body.pwd;

    safe_login(user_id, user_pwd)
        .then((result) => {
            res.send(result);
        })
        .catch((err) => {
            const msg = "\n" + err.message + "\t" + getCurrentTime();
            console.log(msg)
            fs.readFile('C:/test/log.txt', 'utf8', function (err, data) {
                if (err) {
                    return res.status(500).send(err); //@violation
                }
                fs.writeFile('C:/test/log.txt', data + msg, function (err) {
                    if (err) {
                        return res.status(500).send(err); //@violation
                    }
                    // console.log('The file has been updated!');
                });
                return res.send("Login Fail");
            });
        });
});
module.exports = router;