

/* OD_056 buffer_access2 from opus */
void OD_056_function1(int n, int m, int *p){
  int a;
  if(p == 0) return;
  a = n + m;

  if(a < 10){
    a = n - m;
  }

  p[a + n] = 10;
}

void OD_056_function2(int x){
  int* arr1 = new int[10];
  if(arr1 == 0) {
    return;
  }

  int* arr2 = new int[20];
  if(arr2 == 0) {
    return;
  }

  int *p;
  if(x > 10){
    p = arr1;
  }
  else {
    p = arr2;
  }
  
  if(x > 20){
    OD_056_function1(10, 10, p); //@violation OVERRUN.DYNAMIC
  }

  delete[] arr1;
  delete[] arr2;
}
