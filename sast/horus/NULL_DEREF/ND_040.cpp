#include <memory.h>

/* ND_040 - two dereference5 from opus */
void ND_040_function1(char** pp) {
  **pp = 'a'; 
}

void ND_040_function2(int i) {
  char **p = 0;
  char *ptr = 0;
  char buf[10];
  memset(buf, 0, sizeof(buf));
  ptr = buf;
  if(i) {
    p = &ptr;
  }
  else {
    ;
  }

  ND_040_function1(p);	//@violation NULL_DEREF
}
