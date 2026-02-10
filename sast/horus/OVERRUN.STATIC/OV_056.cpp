

/* OV_056 buffer_access2 from opus */
void OV_056_function1(int n, int m, int *p){
  int a;
  if(p == 0) return;
  a = n + m;

  if(a < 10){
    a = n - m;
  }

  p[a + n] = 10;
}

void OV_056_function2(int x){
  int arr1[10];
  int arr2[20];
  int *p;
  if(x > 10){
    p = arr1;
  }
  else {
    p = arr2;
  }
  
  if(x > 20){
    OV_056_function1(10, 10, p); //@violation OVERRUN.STATIC
  }
}
