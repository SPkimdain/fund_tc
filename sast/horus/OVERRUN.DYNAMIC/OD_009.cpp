//@checker OVERRUN.DYNAMIC
/* OD_009 - Function call, deep depth */

bool OD_009_function1(bool flag, int* value) {
  if(flag == false) {
    value[6] = 100; 
    return true;
  }
  return false;
}


bool OD_009_function2(int* value) {
  return OD_009_function1(false, value); 
}

void OD_009_function3(bool flag, int* data1, int* data2) {
  if(flag == true) {
    OD_009_function2(data1);
  }
  else{
    OD_009_function2(data2); 
  }
}

int OD_009_function4() {
  int* data1 = new int[10];
  if(data1 == 0) {
    return 0;
  }

  int* data2 = new int[5];
  if(data2 == 0) {
    return 0;
  }
  OD_009_function3(true, data1, data2); //It's ok.
  OD_009_function3(false, data1, data2); //@violation OVERRUN.DYNAMIC

  delete[] data1;
  delete[] data2;
  return 0;
}


