
/* RF_004 - for */

int* RF_004_function() {
  int* arr = new int[100];
  for(int i = 0; i < 100; i++){
    arr[i] = i + 3;
  }

  delete[] arr;

  return arr + 1; //@violation RETURN_FREE
}


