var x = 1; // Ok
var y = (1 + 1); // Ok
var z = ((1 + 1) + 2); //no @violation
var xy = (((2))) + (1+1); // @violation
var z = ((1 + 1)); // @violation