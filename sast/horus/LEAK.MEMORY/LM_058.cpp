/* LM_058 - Meaningless function call */

int LM_058_function1(int* arg, int flag) {
  if(flag > 0) {
    delete[] arg;
    return 1;
  }
  else {
    return 0;
  }
}

void LM_058_function2(int flag) {
  int* x = new int[10];
  
  LM_058_function1(x, flag);
  
  return;
} //@violation LEAK.MEMORY
