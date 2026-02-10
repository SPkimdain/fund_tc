
var http = require('http');
var url = require('url');

var func = function(req, res) {
  var queryData = url.parse(req.url, true).query;
  var name = queryData.name;
  eval('var name = ' + name + ';'); // @violation
};

http.createServer(func).listen(1337, '127.0.0.1');

yahoo=location.href;
function run(disco){
  eval(disco);
}
run(yahoo);  // @violation