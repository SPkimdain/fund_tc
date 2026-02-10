
/* DBZ_009 - Function call, deep depth */

bool DBZ_009_function1(bool flag, int value) {
  if(flag == false) {
    int ret = 500 / value; // DIV_BY_ZERO
    return true;
  }
  return false;
}


bool DBZ_009_function2(int value) {
  return DBZ_009_function1(false, value); 
}

void DBZ_009_function3(bool flag, int data1, int data2) {
  if(flag == true) {
    DBZ_009_function2(data1);
  }
  else{
    DBZ_009_function2(data2); 
  }
}

int DBZ_009_function4() {
  int actValue = 20;
  int data1 = actValue;
  int data2 = 0;
  DBZ_009_function3(false, data1, data2); //@violation DIV_BY_ZERO

  return 0;
}


