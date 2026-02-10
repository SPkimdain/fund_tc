/* explicit constant, unsigned -> signed */

void CAV_006_function(int flag){  
  char ch = 50;

  if(flag > 0) {
    ch = 250U; //@violation CAST_ALTERS_VALUE.EXT
  }
  else {
    ch = 127U; //It's ok.
  }
}
