
/* OSBC_020 - % operator */
void OSBC_020_function1(int* arr, char* idx) {
  arr[(unsigned int)*idx % 255U] = 10;  
}

void OSBC_020_function2(char* dbp) {
  int arr[256];
  OSBC_020_function1(arr, dbp); //It's ok.
}


void OSBC_020_function3(int idx) {
  int buf[10];

  if(idx >= 0 && idx <= 10) {
    buf[idx] = 10;             //@violation OVERRUN.STATIC.BAD_COND
  }
}
