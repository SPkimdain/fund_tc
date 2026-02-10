/* unknown value, unsigned -> signed */

void CAV_010_function(int flag, unsigned char arg){
  char x = 0;
  unsigned long y = 0;

  x = arg; //It's ok.
  if(arg > 200) {
    x = arg; //@violation CAST_ALTERS_VALUE.EXT
  }
}
