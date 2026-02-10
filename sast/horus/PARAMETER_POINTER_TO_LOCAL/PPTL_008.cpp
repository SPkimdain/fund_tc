
/* PPTL_008 - function call */
int* PPTL_008_function2(int* x, int* y, int flag) {
  flag++;
  if(flag > 10) {
    return x;
  }

  return y;
}

void PPTL_008_function3(int check, int* out, int** out2) {
  int arr[100];

  if(check == 0) {
    return;
  }

  int* ptr = 0;

  if(check > 100) {
    ptr = PPTL_008_function2(arr, out, 10);
  }

  *out2 = ptr; //@violation PARAMETER_POINTER_TO_LOCAL
}

