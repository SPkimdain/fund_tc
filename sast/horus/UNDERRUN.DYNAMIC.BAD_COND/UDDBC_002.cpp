
/* UDDBC_002 - buffer_overrun_trigger from opus */
void UDDBC_002_function1(int x, int *arr){
  int y = 5;
  int z = y;
  if(x >= 0){ // x = [, +oo]

    if(x + 1 < 0){ //@symbolic expression x + 1
      //y = 100 / y;
    }
    //buffer overrun trigger
    arr[x - 1] = 100; 
  }
}

void UDDBC_002_function2(int v) {
  int* datas = new int[10];
  if(datas == 0) {
    return;
  }
  
  if(v >= 0) { //[0, max]
    UDDBC_002_function1(v, datas); //@violation UNDERRUN.DYNAMIC.BAD_COND
  }

  delete[] datas;
}
