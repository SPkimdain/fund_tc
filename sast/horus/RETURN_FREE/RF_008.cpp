
/* RF_008 - function call */
int* RF_008_function2(int* x, int* y, int flag) {
  flag++;
  if(flag > 10) {
    return x;
  }

  return y;
}

int* RF_008_function3(int check, int* out) {
  int* arr = new int[100];

  if(check == 0) {
    delete[] arr;

    return 0;
  }

  int* ptr = 0;

  if(check > 100) {
    ptr = RF_008_function2(arr, out, 10);
  }

  delete[] arr;

  return ptr; //@violation RETURN_FREE
}

