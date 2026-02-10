
/* OSBC_002 - buffer_overrun_trigger from opus */
void OSBC_002_function1(int x, int *arr){
  int y = 0;
  if(x > 0){ // x = [1, +oo]

    //buffer overrun trigger 
    arr[x + 1] = 100; 
  }
}

void OSBC_002_function2(int x) {
  int datas[10] = { 0, };

  if(x <= 9) { //[min, 9]
    OSBC_002_function1(x, datas); //@violation OVERRUN.STATIC.BAD_COND
  }
}
