/* interval, signed -> unsigned */

void CAV_019_function(int data) {
  unsigned int value = 0;
  
  if(data >= 0) {
    value = data; //It's ok.
  }
  else {
    value = data; //@violation CAST_ALTERS_VALUE.EXT
  }

}

