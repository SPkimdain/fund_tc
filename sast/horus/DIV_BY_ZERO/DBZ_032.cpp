#include <stdlib.h>

/* DBZ_032 - diffcult_error from opus */
struct DBZ_032_Struct {
  struct DBZ_032_Struct *next;
  int val;
};

struct DBZ_032_Struct * DBZ_032_function1(int x){
  struct DBZ_032_Struct *node = (DBZ_032_Struct*)malloc(sizeof(struct DBZ_032_Struct));
  if(node == 0) exit(1);
  node->val = x + 1;
  return node;
}

int DBZ_032_function2(){
  int x = 10;
  struct DBZ_032_Struct *cur = DBZ_032_function1(x);
  
  cur->next = DBZ_032_function1(x + 1);
  

  x = x / (cur->val - cur->next->val + 1); //@violation DIV_BY_ZERO

  free(cur->next);
  free(cur);
  return x;
}
