
/* TOBC_002 - buffer_overrun_trigger from opus */
struct TOBC_002_Struct {
  int datas[10];
};

void TOBC_002_function1(int x, int *arr){
  int y = 0;
  if(x > 0){ // x = [1, +oo]
    //buffer overrun trigger 
    arr[x + 1] = 100; 
  }
}

void TOBC_002_function2(int x) {
  TOBC_002_Struct obj;

  if(x <= 9) {
    TOBC_002_function1(x, obj.datas); //@violation TYPE_OVERRUN.BAD_COND
  }
}
