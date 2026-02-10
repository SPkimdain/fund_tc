#include <stdio.h>
#include <stdlib.h>

/* FNH_018 - assgin struct. */
struct FNH_018_Struct {
  int a;
  struct FNH_018_Struct *next;
  float c;
};

int FNH_018_function1(struct FNH_018_Struct *ptr) {
  free(ptr);
  return 1;
}

int FNH_018_function2(int argc, char *argv[]) {
  struct FNH_018_Struct *ptr;
  struct FNH_018_Struct test;
  int ret = 0;

  ptr = (FNH_018_Struct*)malloc(sizeof(FNH_018_Struct));
  if(ptr == 0) {
    return -1;
  }

  ptr->a = 10;
  ptr->next = 0;
  ptr->c = 0.5F;

  test = *ptr; //Copy fields. It's not object copy.
  ret = FNH_018_function1(&test); //@violation FREE_NON_HEAP
  if(ret == 1) {
    free(ptr);
  }

  return 0;
}
