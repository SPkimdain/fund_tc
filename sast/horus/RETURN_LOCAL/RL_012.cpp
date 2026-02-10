
/* RL_012 - RETURN_LOCAL simple example */

int* RL_012_function2(int* obj1) {
  int* ptr = obj1;
  
  if(*ptr == 10) {
    return 0;
  }

  return ptr;
}


int* RL_012_function3(int kind) {
  int arr[100] = { 0, };
  int* x = new int();
  int y = 10;

  switch(kind) {
  case 0:
    return RL_012_function2(x); //It's ok.
    
  case 1:
    delete x;
    return RL_012_function2(&y); //It's ok.

  case 2:
    delete x;
    return RL_012_function2(arr + 5); //@violation RETURN_LOCAL
    break;

  default:
    delete x;
    return 0;
  }
}

