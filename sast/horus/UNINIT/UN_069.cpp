#include <stdio.h>
#include <stdlib.h>

/* UN_069 - malloc1 */
struct UN_069_Struct {
  int a;
  struct UN_069_Struct *next;
  float c;
};

int UN_069_function1(int argc, char *argv[]) {
  struct UN_069_Struct *ptr;
  struct UN_069_Struct test;
  int ret = 0;

  ptr = (UN_069_Struct*)malloc(sizeof(UN_069_Struct));
  if(ptr == 0) {
    return -1;
  }

  ptr->a = 10;
  ptr->next = 0;
  ptr->c = 0.5F;

  test = *ptr; //It's ok.
  
  free(ptr);

  return 0;
}

int UN_069_function2() {
  struct UN_069_Struct *ptr;
  struct UN_069_Struct test;
  int ret = 0;

  ptr = (UN_069_Struct*)malloc(sizeof(UN_069_Struct));
  if(ptr == 0) {
    return -1;
  }

  test = *ptr; //@violation UNINIT

  free(ptr);

  return 0;
}
