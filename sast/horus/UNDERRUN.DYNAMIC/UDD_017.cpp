
/* UDD_017 - unary operator order */
void UDD_017_function() {
  int p = 10;
  int* ptr = 0;
  int ret = 0;
  int** arr = new int*[2];
  if(arr == 0) {
    return;
  }

  arr[0] = &p;
  arr[1] = 0;

  int index = 0;

  ptr = arr[index--]; //It's ok.

  index = 0;
  ptr = arr[--index]; //@violation UNDERRUN.DYNAMIC

  delete[] arr;
}
