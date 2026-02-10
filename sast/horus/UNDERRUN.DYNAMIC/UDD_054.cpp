
/* UDD_054 - boundary index */
void UDD_054_function(int value) {
  int* arr = new int[10];
  if(value < 0) { //Wrong check.
    arr[value] = 10; //@violation UNDERRUN.DYNAMIC
  }

  delete[] arr;
}

