var db = openDatabase('mydb', '1.0', 'Test DB', 2 * 1024 * 1024); //@violation
var db2 = openDatabase('database', '1.0', 'Test DB', 2 * 1024 * 1024); //@violation
var db3 = openDatabase('mydb2', '1.0', 'Test DB', 2 * 1024 * 1024);
var db4 = openDatabase('mydb3', '1.0', 'Test DB', 2 * 1024 * 1024);