
/* TOBC_009 - Function call, deep depth */
struct TOBC_009_Struct {
  int data1[10];
  int data2[5];
};


bool TOBC_009_function1(bool flag, int* value, unsigned index) {
  if(flag == false) {
    value[index] = 100;
    return true;
  }
  return false;
}


bool TOBC_009_function2(int* value, unsigned index) {
  return TOBC_009_function1(false, value, index);
}

void TOBC_009_function3(bool flag, int* data1, int* data2, unsigned index) {
  if(flag == true) {
    TOBC_009_function2(data1, index);
  }
  else{
    TOBC_009_function2(data2, index);
  }
}

int TOBC_009_function4(unsigned index) {
  TOBC_009_Struct obj;
  if(index <= 5)  { // [0, 5]
    TOBC_009_function3(true, obj.data1, obj.data2, index); //It's ok.

    TOBC_009_function3(false, obj.data1, obj.data2, index); //@violation TYPE_OVERRUN.BAD_COND
  }

  return 0;
}
