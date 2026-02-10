/**
 * Module dependencies.
 */

var express = require('express');
var pg = require('pg');
var routes = require('./routes');
var user = require('./routes/user');
var http = require('http');
var path = require('path');
var JADE = require('jade');
var OPEN = require('open');
var HashMap = require('hashmap').HashMap;
var Set = require("collections/set");
var app = express();
global.engine_list = require("./configure").engine;


// all environments
app.set('port', process.env.PORT || 3000);
app.set('views', __dirname + '/views');
app.set('view engine', 'jade');
app.locals.basedir = '.';
app.use(express.favicon());
app.use(express.logger('dev'));
app.use(express.bodyParser());
app.use(express.methodOverride());
app.use(app.router);
app.use(express.cookieParser());
app.use(express.static(path.join(__dirname, '.')));

// development only
if ('development' == app.get('env')) {
    app.use(express.errorHandler());
}


app.get('/index', function (req,res) {
    console.log(req.url); //@violation
    return null;
});

app.post('/test', function(req, res) {
   console.log(req.query.url); //@violation
});

console.log(req.url); //no violation

http.createServer(app).listen(app.get('port'), function () {
    console.log('Express server listening on port ' + app.get('port'));
});
