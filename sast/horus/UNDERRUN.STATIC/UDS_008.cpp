
/* UDS_008 - Function call, return value */
int UDS_008_function1(int flag) {
  if(flag > 10) {
    return -1;
  }
  else {
    return 0;
  }
}

void UDS_008_function2() {
  int value[5] = { 1, };
  int index = UDS_008_function1(5);
  value[index] = 10; //It's ok.

  index = UDS_008_function1(20);
  value[index] = 30; //@violation UNDERRUN.STATIC
}
