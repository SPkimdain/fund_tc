//Example 1
var danger = document.cookie; //src
var dd2 = danger.substring(1,4); //propagation
var dd3 = dd2.split("-");
document.cookie = danger; //@violation
document.cookie = dd3; //@violation



//Example 2
var author = document.form.author.value;
document.cookie = "author=" + author + "; some data"; //@violation
