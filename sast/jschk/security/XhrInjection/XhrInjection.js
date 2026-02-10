var danger = document.URL;
var xhr = new XMLHttpRequest();

xhr.open("", danger, false);//@violation

XMLHttpRequest.open("", danger, false);//@violation