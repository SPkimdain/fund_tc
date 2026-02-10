/* explicit value, smaller type */

void CAV_003_function(int flag) {
  int xValue = 35000;
  int xValue2 = 120;
  short xValue3 = -1;
  char yValue = 0;

  switch(flag) {
  case 0:
    yValue = xValue; //@violation CAST_ALTERS_VALUE.EXT
    break;
  case 1:
    yValue = xValue2; //It's ok.
    break;
  case 2:
    yValue = xValue3; //It's ok.
    break;
  }
    
}

