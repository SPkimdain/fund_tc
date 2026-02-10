#include <stdio.h>

/* LR_020 - veriserve1 from opus */
int LR_020_function1(const char *name, void **pf) {
  void *f = fopen(name, "r");
  if(!f) {
    return -1;
  }
  *pf = f;
  return 0;
}

int LR_020_function2(const char *name) {
  void *dummy;
  if(LR_020_function1(name, &dummy) == -1) {
    fprintf(stderr, "Problem with: %s\n", name);
    return 0;
  }
  return 1; 
} //@violation LEAK.RESOURCE

