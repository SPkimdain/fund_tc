
/* UDSBC_002 - buffer_overrun_trigger from opus */
void UDSBC_002_function1(int x, int *arr){
  int y = 0;
  if(x >= 0){ // x = [0, +oo]

    if(x + 1 < 0){ //@symbolic expression x + 1
      y++;
    }
    //buffer overrun trigger 
    arr[x - 1] = 100; 
  }
}

void UDSBC_002_function2(int x) {
  int datas[10] = { 0, };

  if(x >= 0) { //[0, max]
    UDSBC_002_function1(x, datas); //@violation UNDERRUN.STATIC.BAD_COND
  }
}
