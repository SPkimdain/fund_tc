
/* NDCD_003 - if branch1 */
void NDCD_003_function(int arg, int* out) {
  int value = 10;
  int* ptr = out;
  if(arg == 10) {
    value = 20;
  }
  else {
    *ptr = 10;     
  }

  if(ptr == 0) { //@violation NULL_DEREF.CHECK_AFTER_DEREF
    value++;
  }
}
