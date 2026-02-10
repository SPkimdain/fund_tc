//@checker UNDERRUN.STATIC
/* UDS_009 - Function call, deep depth */

bool UDS_009_function1(bool flag, int* value) {
  if(flag == false) {
    value[-2] = 100; 
    return true;
  }
  return false;
}


bool UDS_009_function2(int* value) {
  return UDS_009_function1(false, value); 
}

void UDS_009_function3(bool flag, int* data1, int* data2) {
  if(flag == true) {
    UDS_009_function2(data1);
  }
  else{
    UDS_009_function2(data2); 
  }
}

int UDS_009_function4() {
  int data1[10] = { 0, };
  int data2[5] = { 1, };
  UDS_009_function3(false, data1, data2); //@violation UNDERRUN.STATIC

  return 0;
}


