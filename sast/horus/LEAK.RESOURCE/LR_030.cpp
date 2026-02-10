#include <stdio.h>

/* LR_030 - faild getting resource */
void LR_030_function1(){
  FILE* fp = fopen("test.txt", "r");
  
  if(fp == 0) {
    /* failed to open file. */
    return;
  } // It's ok.
  
  fclose(fp);
  return;
}

void LR_030_function2(){
  FILE* fp = fopen("test.txt", "r");
  
} //@violation LEAK.RESOURCE

