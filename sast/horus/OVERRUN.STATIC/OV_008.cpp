
/* OV_008 - Function call, return value */
int OV_008_function1(int flag) {
  if(flag > 10) {
    return 10;
  }
  else {
    return 0;
  }
}

void OV_008_function2() {
  int value[5] = { 1, };
  int index = OV_008_function1(5);
  value[index] = 10; //It's ok.

  index = OV_008_function1(20);
  value[index] = 30; //@violation OVERRUN.STATIC
}
