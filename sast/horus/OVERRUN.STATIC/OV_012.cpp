
/* OV_012 - for */
void OV_012_function() {
  int value = 0;
  int arg[3] = { 1, };
  for(int i = 0; i < 10; i++) {
    value++;
  }

  arg[4] = 10; //@violation OVERRUN.STATIC  
}

