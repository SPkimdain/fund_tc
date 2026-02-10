
/* OD_057 - boundary index */
void OD_057_function(int value) {
  int* arr = new int[10];
  if(value > 10) { //Wrong check.
    arr[value] = 10; //@violation OVERRUN.DYNAMIC
  }

  delete[] arr;
}

