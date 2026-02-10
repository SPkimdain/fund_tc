
/* UDD_004 - if branch2 */
void UDD_004_function(int arg) {
  int* value = new int[4];
  if(value == 0) {
    return;
  }

  int* ptr = 0;
  if(arg == 10) {
    ptr = (value + 1);
  }
  else {
    ptr = (value - 5);
  }

  *ptr = 10; //@violation UNDERRUN.DYNAMIC
  delete[] value;
}
