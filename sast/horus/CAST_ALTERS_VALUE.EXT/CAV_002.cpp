/* explicit value, unsigned -> signed */

void CAV_002_function(int flag){
  unsigned char x = 250;
  unsigned char some = 95;
  char ch = 'x';

  if(flag > 100) {
    ch = x; //@violation CAST_ALTERS_VALUE.EXT
  }
  else {
    ch = some; //It's ok.
  }
}
