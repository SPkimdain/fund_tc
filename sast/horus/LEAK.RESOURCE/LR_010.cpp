#include <stdio.h>

/* LR_010 - multiple return */
void LR_010_function(int flag, int flag2) {
  FILE* fp = fopen("1234.txt", "r");

  if(fp == 0) {
    return;
  }

  FILE* fp2 = fopen("abcd.txt", "r");

  if(fp2 == 0) {
    fclose(fp);
    return;
  }

  FILE* fp3 = fopen("efeg.txt", "r");

  if(fp3 == 0) {
    fclose(fp);
    fclose(fp2);
    return;
  }

  fclose(fp3); //fp is released.

  if(flag > 10) {
    fclose(fp2); //fp2 is released.
    if(flag2){
      fclose(fp); //fp is released.
      return; //It's ok.
    }
    else {
      //fp is not released.
      return;
    } //@violation LEAK.RESOURCE
  }
  else {
    fclose(fp2); //ptr is released.
    fclose(fp); //ptr is released.
    return; //It's ok.
  }
}
