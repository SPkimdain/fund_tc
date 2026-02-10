// @checker INPUT_FUNCTION_ERROR_HANDLING
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

int IFERRH_001_function1()
{
  long num_long;

  if(scanf("%ld", &num_long) != 1) {	//@violation	INPUT_FUNCTION_ERROR_HANDLING
                                      //...
  }
  return 0;
}

int IFERRH_001_function2()
{
  long num_long;

  if(scanf("%ld", &num_long) != 1) {
    //....
  }
  else if(ERANGE == errno) {
    if(puts("number out of range\n") == EOF) {

    }
  }
  return 0;
}

int IFERRH_001_function3()
{
  char str1[10], str2[10], str3[10];
  int year;
  FILE * fp;
  long num_long;

  fp = fopen("file.txt", "w+");
  fputs("We are in 2012", fp);

  rewind(fp);
  fscanf(fp, "%d %s %s %s %d", &year, str1, str2, str3);	//@violation	INPUT_FUNCTION_ERROR_HANDLING

  printf("Read String1 |%s|\n", str1);
  printf("Read String2 |%s|\n", str2);
  printf("Read String3 |%s|\n", str3);
  printf("Read Integer |%d|\n", year);

  fclose(fp);

  return(0);
}
