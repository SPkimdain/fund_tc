
/* UDD_008 - Function call, return value */
int UDD_008_function1(int flag) {
  if(flag > 10) {
    return -10;
  }
  else {
    return 0;
  }
}

void UDD_008_function2() {
  int* value = new int[5];
  if(value == 0) {
    return;
  }
  int index = UDD_008_function1(5);
  value[index] = 10; //It's ok.

  index = UDD_008_function1(20);
  value[index] = 30; //@violation UNDERRUN.DYNAMIC
  delete[] value;
}
