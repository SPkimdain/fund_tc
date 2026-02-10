
/* UDS_017 - unary operator order */
void UDS_017_function() {
  int p = 10;
  int* ptr = 0;
  int ret = 0;
  int* arr[2];

  arr[0] = &p;
  arr[1] = 0;

  int index = 0;

  // index - 1 after assign arr[0].
  ptr = arr[index--]; //It's ok.

  index = 0;
  // access arr[-1] after index - 1.
  ptr = arr[--index]; //@violation UNDERRUN.STATIC
}
