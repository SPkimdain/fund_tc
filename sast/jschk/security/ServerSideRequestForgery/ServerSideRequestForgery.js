function violation() {
  var http = require('http');
  var url = require('url');

  function listener(request, response) {
    var request_url = url.parse(request.url, true)['query']['url'];     // @violation
    http.request(request_url)
  }
  http.createServer(listener).listen(8080);
}

function good1() {
  var http = require('http');
  var url = require('url');

  function listener(request, response) {
    var urlText = request.url;

    if(urlText == "https://example.com") {                          // good
      var request_url = url.parse(urlText, true)['query']['url'];
      http.request(request_url);
    }
  }
  http.createServer(listener).listen(8080);
}

function good2() {
  var http = require('http');
  var url = require('url');

  function listener(request, response) {
    var urlText = request.url;

    if("https://test.com".equals(urlText)) {                            // good
      var request_url = url.parse(urlText, true)['query']['url']; 
      http.request(request_url);
    }
  }
  http.createServer(listener).listen(8080);
}

function good3() {
  var http = require('http');
  var url = require('url');

  function listener(request, response) {
    var urlText = request.url;

    if(urlText.startsWith("http://")) {                                 // good
      var request_url = url.parse(urlText, true)['query']['url']; 
      http.request(request_url)
    }
  }
  http.createServer(listener).listen(8080);
}