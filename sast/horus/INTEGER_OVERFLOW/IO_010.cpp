#include <stdlib.h>
#include <stdio.h>

/* IO_010 - function call */

extern int IO_010_allocSize();

int* IO_010_function1(int size){
  return (int*)malloc(size * sizeof(int));
}

int* IO_010_function2(){
  int size2 = IO_010_allocSize();
  return (int*)malloc(size2 * sizeof(int));
}

int* IO_010_function3(int flag) {
  int size = ' ';
  fscanf(stdin, "%c", &size);
  int y = 100;

  switch(flag) {
  case 0:
    return IO_010_function1(size); //@violation INTEGER_OVERFLOW  

  case 1:
    return IO_010_function1(y); //It's ok.

  default:
    break;
  }
  
  return 0;
}

