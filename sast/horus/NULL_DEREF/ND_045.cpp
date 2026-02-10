
/* ND_045 - complex path from opus */
void ND_045_function(int a) {
  int* p = &a;
  if(a > 10){
    p = 0;
  }

  if(a < 10) {
    *p = 10; //It's ok.
  }

  if(a > 0) {
    *p = 5; //@violation NULL_DEREF
  }  
}
