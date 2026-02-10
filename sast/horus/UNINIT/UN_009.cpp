
/* UN_009 - Function call, deep depth */

bool UN_009_function1(bool flag, int* value) {
  if(flag == false) {
    int ret = *value; 
    return true;
  }
  return false;
}


bool UN_009_function2(int* value) {
  return UN_009_function1(false, value); 
}

void UN_009_function3(bool flag, int* data1, int* data2) {
  if(flag == true) {
    UN_009_function2(data1);
  }
  else{
    UN_009_function2(data2); 
  }
}

int UN_009_function4() {
  int data1 = 0;
  int data2;
  UN_009_function3(true, &data1, &data2); //It's ok.

  UN_009_function3(false, &data1, &data2); //@violation UNINIT

  return 0;
}


