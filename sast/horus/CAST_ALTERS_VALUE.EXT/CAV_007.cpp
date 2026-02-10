/* explicit constant, smaller type */

void CAV_007_function(int flag) {
  short value = 0;

  switch(flag) {
  case 10:
    value = 100; //It's ok.
    break;
  case 20:
    value = -32768; //It's ok.
    break;
  case 30:
    value = -32769; //@violation CAST_ALTERS_VALUE.EXT
    break;
  default:
    break;
  }
}

