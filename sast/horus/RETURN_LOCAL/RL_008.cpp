
/* RL_008 - function call */
int* RL_008_function2(int* x, int* y, int flag) {
  flag++;
  if(flag > 10) {
    return x;
  }

  return y;
}

int* RL_008_function3(int check, int* out) {
  int arr[100];

  if(check == 0) {
    return 0;
  }

  int* ptr = 0;
  
  if(check > 100) {
    ptr = RL_008_function2(arr, out, 10);
  }

  return ptr; //@violation RETURN_LOCAL
}

