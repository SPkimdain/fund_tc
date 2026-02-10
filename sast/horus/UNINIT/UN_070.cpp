#include <stdio.h>
#include <stdlib.h>

/* UN_070 - allocation, loop */

double* UN_070_function1() {
  double* data;
  data = (double*)calloc(10,sizeof(double));
  if(data == 0) {
    return 0;
  }

  for(int i = 0; i < 10; i++) {
    printf("%ld", data[i]); //It's ok.
  }

  return data;
}


double* UN_070_function2() {
  double* data;
  data = (double*)malloc(10 * sizeof(double));
  if(data == 0) {
    return 0;
  }

  for(int i = 0; i < 10; i++) {
    printf("%ld", data[i]); //@violation UNINIT
  }

  return data;
}
