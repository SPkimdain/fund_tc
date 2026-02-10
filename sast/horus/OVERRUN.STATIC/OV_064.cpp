/* OV_064 - trace loop counter. */

void OV_064_function(){
  char dest[100];
  unsigned int index;
  for(index = 0; index < 100; index++){
    dest[index] = index;
  }  
  /* i is 100 */
  dest[index] = '\0'; //@violation OVERRUN.STATIC  
}
