const mysql = require('mysql');
const express = require('express');
const app = express();
var router = express.Router();
var mysql2 = require('mysql2');
var mysql2Promise = require("mysql2/promise");

var connection = mysql.createConnection({
	host     : 'localhost',
	user     : 'me',
	password : 'secret',
	database : 'my_db'
});

function violation3(){
	app.get('/person/:id', function(req, res) {
		// Connect to MySQL database.
		var conn = mysql.createConnection({
			host     : 'localhost',
			user     : 'me',
			password : 'secret',
			database : 'my_db'
		});
		conn.connect();
		// Do the query to get data.
		conn.query('SELECT * FROM test WHERE id = ' + req.params.id, function(err, rows, fields) {//@violation
			var person;

			if (err) {
				res.status(500).json({"status_code": 500,"status_message": "internal server error"});
			} else {
				// Check if the result is found or not
				if(rows.length==1) {
					// Create the object to save the data.
					var person = {
						'name':rows[0].name,
						'address':rows[0].address,
						'phone':rows[0].phone,
						'id':rows[0].id
					}
					// render the details.plug page.
					res.render('details', {"person": person});
				} else {
					// render not found page
					res.status(404).json({"status_code":404, "status_message": "Not found"});
				}
			}
		});

		// Close MySQL connection
		conn.end();
	});
}

function violation4(){
	app.get('/person/:id', function(req, res) {
		const id = req.params;
		const sql = 'SELECT * FROM users WHERE id=' + id;
		connection.query(sql, function (err, rows) { //@violation
			//...
		});
	});
}

function violation5(){
	app.get('/person/:id', function(req, res) {
		const id = req.params;
		const sql = 'SELECT * FROM users WHERE id=' + id;
		var pool = mysql.createPool({
			connectionLimit: 10,
			host: 'example.org',
			user: 'bob',
			password: 'secret',
			database: 'my_db'
		});

		pool.query(sql, function (error, results, fields) { //@violation
			if (error) throw error;
			console.log('The solution is: ', results[0].solution);
		});
	});
}

function violation5(){
	app.get('/person/:id', function(req, res) {
		const id = req.params;
		const sql = 'SELECT * FROM users WHERE id=' + id;
		var pool = mysql2.createPool({
			connectionLimit: 10,
			host: 'example.org',
			user: 'bob',
			password: 'secret',
			database: 'my_db'
		});

		pool.query(sql, function (error, results, fields) { //@violation
			if (error) throw error;
			console.log('The solution is: ', results[0].solution);
		});
	});
}

function violation6(){
	app.get('/person/:id', function(req, res) {
		const id = req.params;
		const sql = 'SELECT * FROM users WHERE id=' + id;
		var pool = mysql2Promise.createPool({
			connectionLimit: 10,
			host: 'example.org',
			user: 'bob',
			password: 'secret',
			database: 'my_db'
		});

		pool.query(sql, function (error, results, fields) { //@violation
			if (error) throw error;
			console.log('The solution is: ', results[0].solution);
		});
	});
}

//escapeId 메서드 사용
function good1(){
	app.get('/person/:id', function(req, res) {
		const id = req.params.id;
		const sql = 'SELECT * FROM users WHERE id=' + connection.escape(id);
		connection.query(sql, function (err, rows) { //good
			//...
		});
	});
}

function good2(){
	app.get('/person/:id', function(req, res) {
		const id = req.params.id;
		const sql = 'SELECT * FROM users WHERE id=' + connection.escapeId(id);
		connection.query(sql, function (err, rows) { //good
			//...
		});
	});
}


function bad5() {
	router.post('/login', function (req, res) {
		const id = req.body.input1;
		const pwd = req.body.input2;

		const query = 'SELECT * FROM users WHERE id=' + id;

		connection.query(query, (err, result, field) => {	// @violation

		});
	});
}

function good5() {
	router.post('/login', function (req, res) {
		const id = req.body.input1;
		const pwd = req.body.input2;

		const query = 'SELECT * from info where Id = ? and pwd = ?';

		connection.query(query, [id, pwd], (err, result, field) => {

		});
	});
}


function bad6() {
	app.post('/login', function (req, res) {
		const id = req.body.input1;

		const query = req;

		connection.query(req, (err, result, field) => {	// @violation

		});
	});
}

function good6() {
	router.post('/login', function (req, res) {
		const id = req.body.input1;
		const pwd = req.body.input2;

		const query = 'SELECT * from info where Id = ? and pwd = ?';

		connection.query(query, [id, pwd], (err, result, field) => {

		});
	});
}

// DB.Connect 사용
router.post('/1D_1', function (req, res) {
	const id = req.body.input1;
	const pwd = req.body.input2;
	const query = 'SELECT * FROM info where Id = \'' + id + '\' and pwd = \'' + pwd + '\'';
	connection.query(query, (err, result, field) => {     //@violation
		if (err) return res.status(500).send("ERROR");
		return res.send({Id: result[0].Id, pwd: result[0].pwd});
	});
});
router.post('/1D_2', function (req, res) {
	const query = req.body.content;
	connection.query(query, (err, result, field) => {     //@violation
		if (err) return res.status(500).send("ERROR");
		return res.send(result[0]);
	});
});

String.prototype.format = function () {
	var formatted = this;
	for (var arg in arguments) {
		formatted = formatted.replace("{" + arg + "}", arguments[arg]);
	}
	return formatted;
};
router.post('/1D_3', function (req, res) {
	const id = req.body.input1;
	const pwd = req.body.input2;
	const query = "SELECT * FROM info where Id = \'{0}\' and pwd = \'{1}\'".format(id, pwd);
	connection.query(query, (err, result, field) => {     //@violation
		if (err) return res.status(500).send("ERROR");
		return res.send({Id: result[0].Id, pwd: result[0].pwd});
	});
});

router.post('/1S_1', function (req, res) {
	const id = req.body.input1;
	const pwd = req.body.input2;
	const query = 'SELECT * FROM info where Id = ' + mysql.escape(id) + ' and pwd = ' + mysql.escape(pwd);

	connection.query(query, (err, result, field) => {
		if (err) return res.status(500).send("ERROR");
		return res.send({Id: result[0].Id, pwd: result[0].pwd});
	});
});
router.post('/1S_2', function (req, res) {
	const query = mysql.escape(req.body.content);
	connection.query(query, (err, result, field) => {
		if (err) return res.status(500).send("ERROR");
		return res.send(result[0]);
	});
});

String.prototype.format = function () {
	var formatted = this;
	for (var arg in arguments) {
		formatted = formatted.replace("{" + arg + "}", arguments[arg]);
	}
	return formatted;
};
router.post('/1S_3', function (req, res) {
	const id = req.body.input1;
	const pwd = req.body.input2;
	const query = "SELECT * FROM info where Id = \'{0}\' and pwd = \'{1}\'".format(mysql.escape(id), mysql.escape(pwd));
	connection.query(query, (err, result, field) => {
		if (err) return res.status(500).send("ERROR");
		return res.send({Id: result[0].Id, pwd: result[0].pwd});
	});
});

router.post('/1S_4', function (req, res) {
	const id = req.body.input1;
	const pwd = req.body.input2;

	const query = `SELECT *
                   from info
                   where Id = ?
                     and pwd = ?`;

	connection.query(query, [id, pwd], (err, result, field) => {
		if (err || result.length === 0) return res.status(404).send("Error");
		return res.send({Id: result[0].Id, pwd: result[0].pwd});
	});
});
module.exports = router;