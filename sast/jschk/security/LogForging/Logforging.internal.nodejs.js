var http = require('http');

http.request(options, function(res){
}).on('error', function(e){
  console.log('There was a problem with the request: ' + e);
});