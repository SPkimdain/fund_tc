/* explicit value, signed -> unsigned */

void CAV_001_function(int flag){
  int a;
  unsigned int b;
  a = -20;
  if(flag > 1) {
    b = a - 20;  //@violation CAST_ALTERS_VALUE.EXT
  }
  else {
    b = a + 40; //It's ok. a = 20;
  }
}
