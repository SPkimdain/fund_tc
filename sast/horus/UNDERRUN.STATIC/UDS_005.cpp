
/* UDS_005 - switch branch  */
void UDS_005_function(int arg) {
  int value[4] = { 0, };
  int* ptr = 0;
  switch(arg) {
  case 0:
  case 1:
  case 2:
    ptr = (value + 1);
    break;
  case 3:
    ptr = (value - 4);
    break;
  default:
    ptr = value;
    break;
  }

  *ptr = 10; //@violation UNDERRUN.STATIC
}
