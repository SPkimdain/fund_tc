
/* OV_055 buffer_access from opus */
void OV_055_function1(int n, int m, int *p){
  int a;
  if(p == 0) return;
  a = n + m;

  if(a < 10){
    a = n - m;
  }

  p[a + n] = 10;
}

void OV_055_function2(int x){
  int arr1[10];
  int arr2[20];
  int *p;
  if(x > 10){
    p = arr1;
  }
  else {
    p = arr2;
  }

  if(x < 10){
    OV_055_function1(10, -2, p);//@violation OVERRUN.STATIC
  }
}
