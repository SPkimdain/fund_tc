
/* DF_015 - for */
void DF_015_function(int x) {
  int* ptr = new int(10);

  for(int i = 0; i < x; i++) {
    delete ptr; //@violation DOUBLE_FREE
  }
  
  if(x <= 0) {
    delete ptr;
  }
}
