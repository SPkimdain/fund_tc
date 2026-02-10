
function b(obj:SampleEvent) {  };
xhr.setRequestHeader("Content-Length", "-1000"); // @violation

(function a() {xhr.setRequestHeader("Content-Length", "-1000");})();  // @violation

function test1 () {
    xhr.setRequestHeader("Content-Length", "-1000");  // @violation
}

function test2 () {
    xhr.setRequestHeader("Content-Length", "1000");   // good
}
test();
