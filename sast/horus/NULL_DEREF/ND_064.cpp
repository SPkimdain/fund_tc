#include <setjmp.h>

/* ND_064 - longjmp  */
/* http://localhost:18080/report.spw?defectId=22.500.619 Case. */

jmp_buf ND_064_buf;

void ND_064_function1(int* ptr) {
  if(ptr == 0) {
    longjmp(ND_064_buf, 2);
  }

  *ptr = 10; //It's ok.

  
  int* p = 0;
  *p = 100; //@violation NULL_DEREF  
}


void ND_064_function2(int* ptr) {
  if(setjmp(ND_064_buf) == 2) {
    return;
  };

  ND_064_function1(ptr);
}

