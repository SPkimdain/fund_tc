/* interval, smaller type */

void CAV_021_function(int x) {
  short data = 0;

  if(x >= 0 && x < 10000) {
    data = x; //It's ok.
  }
  else if(x >= 0 && x < 30000) {
    data = x; //It's ok.
  }
  else if(x < -32768) {
    data = x; //@violation CAST_ALTERS_VALUE.EXT
  }
  else {
    data = x; //It's ok.
  }
}


