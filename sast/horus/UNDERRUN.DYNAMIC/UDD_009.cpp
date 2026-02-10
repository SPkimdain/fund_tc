//@checker UNDERRUN.DYNAMIC
/* UDD_009 - Function call, deep depth */

bool UDD_009_function1(bool flag, int* value) {
  if(flag == false) {
    value[-3] = 100; 
    return true;
  }
  return false;
}


bool UDD_009_function2(int* value) {
  return UDD_009_function1(false, value); 
}

void UDD_009_function3(bool flag, int* data1, int* data2) {
  if(flag == true) {
    UDD_009_function2(data1);
  }
  else{
    UDD_009_function2(data2); 
  }
}

int UDD_009_function4() {
  int* data1 = new int[10];
  if(data1 == 0) {
    return 0;
  }

  int* data2 = new int[5];
  if(data2 == 0) {
    return 0;
  }
  UDD_009_function3(false, data1, data2); //@violation UNDERRUN.DYNAMIC

  delete[] data1;
  delete[] data2;
  return 0;
}


