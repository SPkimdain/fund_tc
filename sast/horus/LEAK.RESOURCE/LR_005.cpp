#include <stdio.h>

/* LR_005 - switch branch  */
void LR_005_function(int arg, int flag1, int flag2) {
  int x = 0;
  FILE* fp = fopen("test.txt", "r");

  if(flag1 > 0) {
    if(flag2 == 10) {
      switch(arg) {
      case 0:
      case 1:
      case 2:
        x++; //This flow has a problem.
        break;
      case 3:
        fclose(fp);
        break;
      default:
        fclose(fp);
        break;
      } 
    } 
    else {
      fclose(fp);
    }
  }
  else {
    fclose(fp);
  }

  return;
} //@violation LEAK.RESOURCE
