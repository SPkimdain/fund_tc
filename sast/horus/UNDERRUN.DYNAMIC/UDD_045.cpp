
/* UDD_045 - complex path from opus */
void UDD_045_function(int a) {
  int* p = new int[10];
  if(p == 0) {
    return;
  }
  int* ptr = p;
  if(a > 10){
    ptr = p - 1;
  }

  if(a <= 10) {
    *ptr = 10; //It's ok.
  }

  if(a > 0) {
    *ptr = 5; //@violation UNDERRUN.DYNAMIC
  }  

  delete[] p;
}
