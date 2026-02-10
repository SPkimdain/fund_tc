#include<assert.h>

/* ND_065 - assert  */
/* http://localhost:18080/report.spw?defectId=22.500.477 Case. */

extern void __assert_fail(const char * assertion, const char * file, unsigned int line, const char * function);
extern void ND_065_function2();

#define custom_assert(expr) (expr) ? ND_065_function2() : __assert_fail(#expr, "", 0, "");

struct ND_065_Struct {
  int value;
};

void ND_065_function(ND_065_Struct* obj) {
  custom_assert(obj);

  if(obj->value) { //It's ok.
    return;
  }

  int* p = 0;
  *p = 100; //@violation NULL_DEREF  
}

