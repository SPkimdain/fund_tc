
/* OD_012 - interval size, function */
void OD_012_function1(int size, int index) {
  char* arr = new char[size];
  arr[index] = 'a';
  delete[] arr;
}

void OD_012_function2(int size) {
  if(size < 10) {    
    OD_012_function1(size, 10); //@violation OVERRUN.DYNAMIC
  }
  else if(size == 20) {
    OD_012_function1(size, 10); //It's ok.
  }
}



