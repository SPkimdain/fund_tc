var variableParam = "test"
system(variableParam); //@violation
system("test"); //@violation


system("test", 1);
system(1, 2, 3);

