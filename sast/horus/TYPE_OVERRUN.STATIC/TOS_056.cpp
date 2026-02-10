

/* TOS_056 buffer_access2 from opus */
struct TOS_056_Struct {
  int i;
  char c;
  int arr1[10];
  int arr2[20];
  long l;
};

void TOS_056_function1(int n, int m, int *p){
  int a;
  if(p == 0) return;
  a = n + m;

  if(a < 10){
    a = n - m;
  }

  p[a + n] = 10;
}

void TOS_056_function2(int x){
  TOS_056_Struct sb;
  int *p;
  if(x > 10){
    p = sb.arr1;
  }
  else {
    p = sb.arr2;
  }
  
  if(x > 20){
    TOS_056_function1(10, 10, p); //@violation TYPE_OVERRUN.STATIC
  }
}
