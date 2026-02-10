
/* UDD_012 - interval size, function */
void UDD_012_function1(int size, int index) {
  char* arr = new char[size];
  arr[index] = 'a';
  delete[] arr;
}

void UDD_012_function2(int size) {
  if(size < 10) {    
    UDD_012_function1(size, -1); //@violation UNDERRUN.DYNAMIC
  }
}



