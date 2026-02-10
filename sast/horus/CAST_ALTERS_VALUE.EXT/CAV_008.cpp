/* explicit value, float -> int */

void CAV_008_function(int flag) {
  int ia = 0;
  if(flag > 0) {
    ia = 555.5555; //@violation CAST_ALTERS_VALUE.EXT
  }
  else {
    ia = (int)555.5555; //It's ok.
  }
}

