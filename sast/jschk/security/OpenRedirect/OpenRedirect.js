var express = require('express');
var router = express.Router();

router.post('/dan', function (req, res) {
    const url = req.body.profile_url;
    try{
        res.redirect(url);  //@violation
    }catch (e) {
        return res.status(500).send("ERROR");
    }
});
module.exports = router;