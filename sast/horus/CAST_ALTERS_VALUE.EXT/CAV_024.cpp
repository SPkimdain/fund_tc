/* ignore logical expression */

void CAV_024_function(unsigned long flag){
  
  flag &= ~(0x0008 | 0x0001); //It's ok.
    
  int a;
  unsigned int b;
  a = -20;
  if(flag > 1) {
    b = a - 20;  //@violation CAST_ALTERS_VALUE.EXT
  }  
}

