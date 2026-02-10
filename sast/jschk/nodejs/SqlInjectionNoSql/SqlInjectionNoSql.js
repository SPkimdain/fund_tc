var MongoClient1 = require('mongodb').MongoClient, Server = require('mongodb').Server;
var mongoClient = new MongoClient1(new Server('localhost', 27017));

function useWhereViolation1() {
    mongoClient.open(function(err, client) {
        var db = client.db("mydb");
        db.collection("users").find({ $where: function() { //@violation
            return (hex_md5(this.name) == "9b53e667f30cd329dca1ec9e6a83e994")
        }}).toArray((err, docs) => { });
        client.close();
    });
}

function useWhereViolation2() {
    mongoClient.open(function(err, client) {
        var query = { $where: function() {
            return (hex_md5(this.name) == "9b53e667f30cd329dca1ec9e6a83e994")
        }};
        var db = client.db("mydb");
        var players = db.collection("player");
        players.find(query); //@violation
        client.close();
    });
}

function useWhereViolation3() {
    mongoClient.open((err, client) => {
        var db = client.db("mydb");
        db.collection("users").find({ $where: function() { //@violation
            return (hex_md5(this.name) == "9b53e667f30cd329dca1ec9e6a83e994")
        }}).toArray((err, docs) => { });
        client.close();
    });
}

function useWhereGood1() {
    mongoClient.open(function(err, client) {
        var db = client.db("mydb");
        db.collection("users").find({ $other: function() {
            return (hex_md5(this.name) == "9b53e667f30cd329dca1ec9e6a83e994")
        }}).toArray((err, docs) => { });
        client.close();
    });
}

function useWhereGood2(req, res) {
    mongoClient.open(function(err, client) {
        var query = { $other: function() {
            return (hex_md5(this.name) == "9b53e667f30cd329dca1ec9e6a83e994")
        }};
        var db = client.db("mydb");
        var players = db.collection("player");
        players.find(query);
        client.close();
    });
}

function useWhereGood3(req, res) {
    mongoClient.open((err, client) => {
        var query = { $other: function() {
                return (hex_md5(this.name) == "9b53e667f30cd329dca1ec9e6a83e994")
            }};
        var db = client.db("mydb");
        var players = db.collection("player");
        players.find(query);
        client.close();
    });
}

function violation1(req, res) {
    mongoClient.open(function(err, client) {
        var db = client.db("mydb");
        db.collection("users") //@violation
            .find({ user: req.query.username, city: req.query.password })
            .toArray((err, docs) => { });
        client.close();
    });
}

function violation2(req, res) {
    mongoClient.open(function(err, client) {
        var db = client.db("mydb");
        db.collection("users") //@violation
            .find(req.query.username)
            .toArray((err, docs) => { });
        client.close();
    });
}

function violation3(req, res) {
    mongoClient.open(function(err, client) {
        var db = client.db("mydb");
        var query = { user: req.query.username };
        db.collection("users") //@violation
            .find(query.user)
            .toArray((err, docs) => { });
        client.close();
    });
}

function violation4(req, res) {
    mongoClient.open(function(err, client) {
        var db = client.db("mydb");
        var query = { user: req.query.username, city: req.query.password };
        db.collection("users") //@violation
            .find(query)
            .toArray((err, docs) => { });
        client.close();
    });
}

function violation5(req, res) {
    mongoClient.open(function(err, client) {
        var db = client.db("mydb");
        let query = req.query.username;
        db.collection("users") // @violation
            .find(query).toArray((err, docs) => { });
        client.close();
    });
}

function violation6(req, res) {
    mongoClient.open(function(err, client) {
        var db = client.db("mydb");
        let query = req.query.username;
        var players = db.collection("player");
        players.find(query); // @violation
        client.close();
    });
}

function violation7(req, res) {
    mongoClient.open(function(err, client) {
        var db = client.db("mydb");
        var query = req.query('id');
        db.collection("users") // @violation
            .find(query).toArray((err, docs) => { });
        client.close();
    });
}

function violation8(req, res) {
    mongoClient.open((err, client) => {
        var db = client.db("mydb");
        var query = req.query('id');
        db.collection("users") // @violation
            .find(query).toArray((err, docs) => { });
        client.close();
    });
}

//toString() 하나만 사용
async function violation9(req, res) {
    mongoClient.open(function(err, client) {
        var db = client.db("mydb");
        let query = { user: req.query.username.toString(), city: req.query.password };
        db.collection("users") //@violation
            .find(query)
            .toArray((err, docs) => { });
        client.close();
    });
}

//toString() 사용
async function good1(req, res) {
    mongoClient.open(function(err, client) {
        var db = client.db("mydb");
        let query = { user: req.query.username.toString(), city: req.query.password.toString() };
        db.collection("users")
            .find(query)
            .toArray((err, docs) => { });
        client.close();
    });
}

//String() 사용
async function good2(req, res) {
    mongoClient.open(function(err, client) {
        var db = client.db("mydb");
        let query = { user: String(req.query.username), city: String(req.query.password) };
        db.collection("users")
            .find(query)
            .toArray((err, docs) => { });
        client.close();
    });
}

//toString() , String() 사용
async function good3(req, res) {
    mongoClient.open(function(err, client) {
        var db = client.db("mydb");
        let query = { user: req.query.username.toString(), city: String(req.query.password) };
        db.collection("users")
            .find(query)
            .toArray((err, docs) => { });
        client.close();
    });
}

async function good4(req, res) {
    mongoClient.open((err, client) => {
        var db = client.db("mydb");
        let query = { user: req.query.username.toString(), city: String(req.query.password) };
        db.collection("users")
            .find(query)
            .toArray((err, docs) => { });
        client.close();
    });
}

function good5(req, res) {
    mongoClient.open(function(err, client) {
        var db = client.db("mydb");
        let query = req.query.username;
        aaa.find(query);
        bbb.findOne(query);
        ccc.findone(query);
        client.close();
    });
}