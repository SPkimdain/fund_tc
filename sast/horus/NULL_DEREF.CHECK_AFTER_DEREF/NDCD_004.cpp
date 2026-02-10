
/* NDCD_004 - if branch2 */
void NDCD_004_function(int arg, int* ptr2) {
  int value = 10;
  int* ptr1 = 0;

  *ptr2 = 20;

  if(arg == 10) {
    ptr1 = &value;
  }
  else {
    ptr1 = ptr2;
  }

  if(ptr1 != 0) { //@violation NULL_DEREF.CHECK_AFTER_DEREF
    *ptr1 = 100; 
  }
}
