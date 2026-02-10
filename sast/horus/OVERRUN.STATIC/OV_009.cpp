//@checker OVERRUN.STATIC
/* OV_009 - Function call, deep depth */

bool OV_009_function1(bool flag, int* value) {
  if(flag == false) {
    value[6] = 100; 
    return true;
  }
  return false;
}


bool OV_009_function2(int* value) {
  return OV_009_function1(false, value); 
}

void OV_009_function3(bool flag, int* data1, int* data2) {
  if(flag == true) {
    OV_009_function2(data1);
  }
  else{
    OV_009_function2(data2); 
  }
}

int OV_009_function4() {
  int data1[10] = { 0, };
  int data2[5] = { 1, };
  OV_009_function3(true, data1, data2); //It's ok.
  OV_009_function3(false, data1, data2); //@violation OVERRUN.STATIC

  return 0;
}


