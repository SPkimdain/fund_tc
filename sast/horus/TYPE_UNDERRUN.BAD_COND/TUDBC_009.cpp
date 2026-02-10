
/* TUDBC_009 - Function call, deep depth */
struct TUDBC_009_Struct {
  int data1[10];
  int data2[5];
};


bool TUDBC_009_function1(bool flag, int* value, int index) {
  if(flag == false) {
    value[index] = 100;
    return true;
  }
  return false;
}


bool TUDBC_009_function2(int* value, int index) {
  return TUDBC_009_function1(false, value, index);
}

void TUDBC_009_function3(bool flag, int* data1, int* data2, int index) {
  if(flag == true) {
    TUDBC_009_function2(data1, index);
  }
  else{
    TUDBC_009_function2(data2, index);
  }
}

int TUDBC_009_function4(int index) {
  TUDBC_009_Struct obj;
  if(index >= 0 && index <= 5)  { // [0, 5]
    TUDBC_009_function3(true, obj.data1, obj.data2, index); //It's ok.

    TUDBC_009_function3(false, obj.data1, obj.data2, index - 1); //@violation TYPE_UNDERRUN.BAD_COND
  }

  return 0;
}
