#include <stdlib.h>

/* LM_013 - for2 */
void LM_013_function(int value, int value2) {
  int p = 100;
  int* ptr = 0;

  for(int i = 0; i < 2; i++) {
    if(value > 10) { // True or False
      if(value2 > 5) { // True or False
        ptr = (int*)malloc(4);
      } 
    }
  }
}//@violation LEAK.MEMORY
