/* function call, unsigned -> signed */

unsigned char CAV_014_function1() {
  return 250;
}

void CAV_014_function2(int& data) {
  char ch = 0;
  unsigned char ret = CAV_014_function1();
  unsigned char uch = ret;
  
  ch = uch; //@violation CAST_ALTERS_VALUE.EXT
}



