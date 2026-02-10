#include <stdlib.h>

/* LM_019 - short circuit */
int* LM_019_function1() {
  return (int*)malloc(4);
}

int* LM_019_function2() {
  int* ptr = 0;
  int x = 10;
  int compareValue = 20;
  int ret = 0;

  ptr = LM_019_function1();

  
  return 0; 
  
}//@violation LEAK.MEMORY

