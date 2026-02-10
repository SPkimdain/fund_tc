
/* CAV_030 - ignored number of decision point(option) */

void CAV_030_function1(int flag, int level){
  unsigned long value = 0;

  if(flag > 50) {
    value = 0; //It's ok.
  }
  else if(flag > 10) {
    value = 1; //It's ok.
  }
  else {
    value = -20; //@violation CAST_ALTERS_VALUE.EXT
  }
}
