
/* ND_009 - Function call, deep depth */

bool ND_009_function1(bool flag, int* value) {
  if(flag == false) {
    *value = 100; 
    return true;
  }
  return false;
}


bool ND_009_function2(int* value) {
  return ND_009_function1(false, value); 
}

void ND_009_function3(bool flag, int* data1, int* data2) {
  if(flag == true) {
    ND_009_function2(data1);
  }
  else{
    ND_009_function2(data2); 
  }
}

int ND_009_function4() {
  int actValue = 20;
  int* data1 = &actValue;
  int* data2 = 0;
  ND_009_function3(false, data1, data2);//@violation NULL_DEREF

  return 0;
}


