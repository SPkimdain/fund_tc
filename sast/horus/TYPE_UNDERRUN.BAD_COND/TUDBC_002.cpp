
/* TUDBC_002 - buffer_overrun_trigger from opus */
struct TUDBC_002_Struct {
  int datas[10];
};

void TUDBC_002_function1(int x, int *arr){
  int y = 0;
  if(x >= 0){ // x = [0, +oo]

    if(x + 1 < 0){ //@symbolic expression x + 1
      y++;
    }
    //buffer overrun trigger 
    arr[x - 1] = 100; 
  }
}

void TUDBC_002_function2(int x) {
  TUDBC_002_Struct obj;

  if(x >= 0) {
    TUDBC_002_function1(x, obj.datas); //@violation TYPE_UNDERRUN.BAD_COND
  }
}
