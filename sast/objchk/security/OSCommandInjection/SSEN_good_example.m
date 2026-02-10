 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
 #include <unistd.h>
 #define MAX 100
 int main(intargc, char*argv[])
  {
     char arg[MAX-4];
     char command[MAX] = "cat ";
     fgets(arg, MAX-4, stdin);

     if (strpbrk(arg,";\"'."))
     {
     	return 1;
     }

     strncat(command, arg, MAX-4);
     system(command);
     return 0;
  }
