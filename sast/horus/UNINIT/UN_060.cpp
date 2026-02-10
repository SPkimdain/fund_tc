
/* UN_060 - assign in the loop */

void UN_060_funciton(int x) {
  int arr[100];
  int* ptr1 = 0;
  int* ptr2 = 0;
  for(int i = 0; i < 10; i++) {
    arr[i] = x;
    x++;
  }

  ptr1 = arr;
  ptr2 = arr + 1;

  if(ptr2[-1] == 0) { // It's ok.
    x++;
  }
  
  int a;
  int b;
  b = a; //@violation UNINIT

}
