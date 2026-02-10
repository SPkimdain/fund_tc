#include <stdlib.h>
#include <math.h>

/* PMFE_013 - fmod */
struct PMFE_013_Struct {
  struct PMFE_013_Struct *next;
  int val;
};

struct PMFE_013_Struct * PMFE_013_function1(int x){
  struct PMFE_013_Struct *node = (PMFE_013_Struct*)malloc(sizeof(struct PMFE_013_Struct));
  if(node == 0) exit(1);
  node->val = x + 1;
  return node;
}

int PMFE_013_function2(){
  int x = 10;
  struct PMFE_013_Struct *cur = PMFE_013_function1(x);
  
  cur->next = PMFE_013_function1(x + 1);
  
  //2nd argument is 0;
  float ret = fmod(3.5F, (float)(cur->val - cur->next->val + 1)); //@violation PREVENT_MATH_FUNCTIONS_ERROR

  free(cur->next);
  free(cur);
  return x;
}
