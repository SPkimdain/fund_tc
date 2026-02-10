/* unknown value, signed -> unsigned */

void CAV_009_function(int flag, long arg){
  unsigned long b = 0;

  b = arg; //It's ok. arg is perfectly unknown value.

  if(arg < 0) {
    b = arg; //@violation CAST_ALTERS_VALUE.EXT
  }
}
