try {
	var a = 1;
} catch(e) { //@violation
	//Dom
}

try {
	var c = 2;
} catch(e) { //@Safe
	var d = 1;
	c();
}