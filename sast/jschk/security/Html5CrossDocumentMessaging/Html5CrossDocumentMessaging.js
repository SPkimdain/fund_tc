o.contentWindow.postMessage(message, '*'); // @violation

o.contentWindow.postMessage(message, "*"); // @violation

Window.postMessage(message,22, "*"); // @violation

 function sendMessage(){
    var dest = document.getElementById("co2");
    dest.contentWindow.postMessage("message from co1","*"); // @violation
  }


  window.document.onmousemove = function(e) {
      var x = (window.Event) ? e.pageX : window.event.clientX;
      var y = (window.Event) ? e.pageY : window.event.clientY;
      window.parent.frames[1].postMessage('x = ' + x + ' y = ' + y, '*'); // @violation
  };


  Window.postMessage(message,22 , "*", "test", "dummy"); // @violation


