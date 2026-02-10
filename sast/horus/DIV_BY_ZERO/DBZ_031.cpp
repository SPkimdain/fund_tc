#include <stdlib.h>
#include <memory.h>

/* DBZ_031 - complex alarms1 from opus */
struct DBZ_031_Struct {
  int v;
};

int DBZ_031_function1(int y, struct DBZ_031_Struct *x){
  if(y > 0)
    return y / (x->v);
  else return 10;
}

void DBZ_031_function2(){
  int a = 0, b = 1;
  struct DBZ_031_Struct *x = (DBZ_031_Struct*)malloc(sizeof(struct DBZ_031_Struct));
  if(x == 0) return;
  x->v = b;
  b = DBZ_031_function1(a, x);
  a = b - 10;
  x->v = a;
  b = DBZ_031_function1(b, x);  //@violation DIV_BY_ZERO 
  free(x);
  return;
}
