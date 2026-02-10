
/* TOS_055 buffer_access from opus */
struct TOS_055_Struct {
  int i;
  char c;
  int arr1[10];
  int arr2[20];
  long l;
};

void TOS_055_function1(int n, int m, int *p){
  int a;
  if(p == 0) return;
  a = n + m;

  if(a < 10){
    a = n - m;
  }

  p[a + n] = 10;
}

void TOS_055_function2(int x){
  TOS_055_Struct obj;
  int *p;
  if(x > 10){
    p = obj.arr1;
  }
  else {
    p = obj.arr2;
  }

  if(x < 10){
    TOS_055_function1(10, -2, p);//@violation TYPE_OVERRUN.STATIC
  }
}
