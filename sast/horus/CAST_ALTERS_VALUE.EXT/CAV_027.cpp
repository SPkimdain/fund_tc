/* const define */

#define INT32_MIN (-2147483647 - 1)


void CAV_027_function(int flag, unsigned right){
  
  int ret = right + INT32_MIN;
    
  int a;
  unsigned int b;
  a = -20;
  if(flag > 1) {
    b = a - 20;  //@violation CAST_ALTERS_VALUE.EXT
  }  
}

