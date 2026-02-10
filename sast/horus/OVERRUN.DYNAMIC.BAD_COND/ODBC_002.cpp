
/* ODBC_002 - buffer_overrun_trigger from opus */
void ODBC_002_function1(int x, int *arr){
  int y = 5;
  int z = y;
  if(x > 0){ // x = [1, +oo]
    //buffer overrun trigger, x + 1 = [1, 10]
    arr[x + 1] = 100; 
  }
}

void ODBC_002_function2(int v) {
  int* datas = new int[10];
  if(datas == 0) {
    return;
  }
  
  if(v <= 9) { //[min, 9]
    ODBC_002_function1(v, datas); //@violation OVERRUN.DYNAMIC.BAD_COND
  }

  delete[] datas;
}
