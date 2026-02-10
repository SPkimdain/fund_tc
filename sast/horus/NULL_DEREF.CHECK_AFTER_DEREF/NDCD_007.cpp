//@checker NULL_DEREF.CHECK_AFTER_DEREF
/* NDCD_007 - Function call, return value */
int* NDCD_007_function1(int* arg, int flag) {
  if(flag > 10) {    
    return arg;
  }
  else {
    return 0;
  }
}

void NDCD_007_function2(int* value) {
  int* ptr = NDCD_007_function1(value, 5);

  if(ptr != 0) { //It's ok.
    *ptr = 100;
  }  
}

void NDCD_007_function3(int* value) {  
  int* ptr = NDCD_007_function1(value, 15);

  *ptr = 10;

  if(ptr) { //@violation NULL_DEREF.CHECK_AFTER_DEREF
    *ptr = 20;
  }  
}

