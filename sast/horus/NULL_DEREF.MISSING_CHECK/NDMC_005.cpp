
/* NDMC_005 - switch branch  */
void NDMC_005_function(int arg, int* ptr) {
  switch(arg) {
  case 0:
  case 1:
  case 2:
    break;
  case 3:
    if(ptr != 0) {
      *ptr = 100;
    }
    break;
  default:
    break;
  }  

  *ptr = 10; //@violation NULL_DEREF.MISSING_CHECK
}
