
var http = require('http');
var url = require('url');
var child_process = require('child_process');

var func = function(req, res) {
  var queryData = url.parse(req.url, true).query;
  var name = queryData.name;
  child_process.exec('ls ' + name, function (err, data) { // @violation
    console.log(data);
  });

  var spawn = require('child_process').spawn;
      ls    = spawn(name, ['-lh', '/usr']);  // No violation (function 추적)
};

http.createServer(func).listen(1337, '127.0.0.1');
