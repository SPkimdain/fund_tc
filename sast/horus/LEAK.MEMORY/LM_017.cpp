#include <stdlib.h>

/* ML_017 - unary operator order */
void ML_017_function(int flag, int** ptr1) {
  int p = 10;
  int ret = 0;
  int* arr[2];

  if(flag == 1) {
    arr[0] = (int*)malloc(4);
    if(arr[0] == 0) {
      return;
    }
      
    arr[1] = (int*)malloc(2);
    
    if(arr[1] == 0) {
      free(arr[0]);
      return;
    }
    

    *arr[0] = 10;
    *arr[1] = 2;
    int index = 0;

    /* *ptr1 is arr[0]. */
    *ptr1 = arr[index++]; // index + 1 after assign arr[0].

    index = 0;
    int* ptr = arr[++index]; // assign arr[1] after index + 1.    
  } 
} //@violation LEAK.MEMORY
