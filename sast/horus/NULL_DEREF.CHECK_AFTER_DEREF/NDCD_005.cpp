//@checker NULL_DEREF.CHECK_AFTER_DEREF
/* NDCD_005 - switch branch  */
void NDCD_005_function(int arg, int& value) {

  int* ptr = &value;

  switch(arg) {
  case 0:
  case 1:
  case 2:
    break;
  case 3:
    *ptr = 20;
    break;
  default:
    break;
  }

  if(ptr) { //@violation NULL_DEREF.CHECK_AFTER_DEREF
    *ptr = 10; 
  }

}
