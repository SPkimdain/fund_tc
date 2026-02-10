
/* UDD_005 - switch branch  */
void UDD_005_function(int arg) {
  int* value = new int[4];
  if(value == 0) {
    return;
  }

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

  *ptr = 10; //@violation UNDERRUN.DYNAMIC
  delete[] value;
}
