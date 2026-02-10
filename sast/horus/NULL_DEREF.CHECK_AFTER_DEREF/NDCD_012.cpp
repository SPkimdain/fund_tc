//@checker NULL_DEREF.CHECK_AFTER_DEREF
/* NDCD_012 - Extern value dereference in the loop */
extern int* NDCD_012_function1(int** arr, int index) {
  return arr[index];
}

void NDCD_012_function2(int** arr) {
  int count = 0;
  for(int i = 0; i < 10; i++) {
    int* ret = NDCD_012_function1(arr, i);
    if(ret != 0 && *ret == 10) { //It's ok.
      break;
    }
    count++;
  }

  count = 0;

}

void NDCD_012_function3(int* p) {
  *p = 100; 

  if (p){ //@violation NULL_DEREF.CHECK_AFTER_DEREF
	  int i = 0;
  }
}
