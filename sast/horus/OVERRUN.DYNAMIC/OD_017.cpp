
/* OD_017 - unary operator order */
void OD_017_function() {
  int p = 10;
  int* ptr = 0;
  int ret = 0;
  int** arr = new int*[2];
  if(arr == 0) {
    return;
  }

  arr[0] = &p;
  arr[1] = 0;

  int index = 1;

  // index + 1 after assign arr[1].
  ptr = arr[index++]; //It's ok.

  index = 1;
  // access arr[2] after index + 1.
  ptr = arr[++index]; //@violation OVERRUN.DYNAMIC

  delete[] arr;
}
