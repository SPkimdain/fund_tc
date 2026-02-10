
/* ND_005 - switch branch  */
void ND_005_function(int arg) {
  int value = 10;
  int* ptr = &value;
  switch(arg) {
  case 0:
  case 1:
  case 2:
    break;
  case 3:
    ptr = 0;
    break;
  default:
    break;
  }

  *ptr = 10; //@violation NULL_DEREF
}
