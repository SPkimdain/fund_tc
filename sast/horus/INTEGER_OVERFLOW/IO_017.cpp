#include <stdlib.h>
#include <stdio.h>

/* IO_017 - taint, fscanf */
void IO_017_function2(int size){
  int data;
  /* Initialize data */
  data = -1;
  fscanf(stdin, "%d", &data);

  int result = data * 5;  //@violation INTEGER_OVERFLOW
}
