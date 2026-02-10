#include <stdio.h>

/* LR_001 - simple case */
void LR_001_function(){
  FILE* fp = fopen("test.txt", "r");
  
} //@violation LEAK.RESOURCE

