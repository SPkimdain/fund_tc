obj = new XMLHttpRequest();
obj.open('GET','/fetchusers.jsp?id='+form.id.value,'true','scott',''); //@violation
var c = "";
obj.open('GET','/fetchusers.jsp?id='+form.id.value,'true','scott', c); //@violation
d = c;
obj.open('GET','/fetchusers.jsp?id='+form.id.value,'true','scott', d); //@violation
var e = "test";
obj.open('GET','/fetchusers.jsp?id='+form.id.value,'true','scott', e); //good