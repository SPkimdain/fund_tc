#include <stdlib.h>

/* LM_028 - veriserve_01_01 from opus */
int LM_028_function(unsigned int size) {

  char *p_str, *p_str1;
  char *p_strback, *p_strback1;

  p_str = (char*)malloc(size);
  if(p_str == 0)  return 1;
  p_strback = p_str;
  p_str1 = (char*)malloc(size);
  if(p_str1 == 0){
    free(p_str);
    return 2;
  }

  p_strback1 = p_str1;
  p_str = p_str1;

  free(p_strback1);
  return size;   
}//@violation LEAK.MEMORY

