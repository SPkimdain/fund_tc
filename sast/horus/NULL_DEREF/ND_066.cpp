#include<stddef.h>

/* ND_065 - offsetof  */

struct ND_066_Struct {
  char a;
  char b[10];
  char c;
};

void ND_066_function(char* buf) {
  offsetof(ND_066_Struct, a); //It's ok.

  int* p = 0;
  *p = 100; //@violation NULL_DEREF  
}

