/* unknown value, smaller type */

void CAV_011_function(int flag, int arg) {
  short yVal = 0;
  if(arg > 70000) {
    yVal = arg; //@violation CAST_ALTERS_VALUE.EXT
  }
  else if(arg > 0) {
    yVal = arg; //It's ok.
  }
  else {
    yVal = arg; //It's ok.
  }
}

