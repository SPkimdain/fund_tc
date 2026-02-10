
/* UDS_045 - complex path from opus */
void UDS_045_function(int a) {
  int p[10] = { 0, };
  int* ptr = p;
  if(a > 10){
    ptr = p - 5;
  }

  if(a <= 10) {
    *ptr = 10; //It's ok.
  }

  if(a > 0) {
    *ptr = 5; //@violation UNDERRUN.STATIC
  }  
}
