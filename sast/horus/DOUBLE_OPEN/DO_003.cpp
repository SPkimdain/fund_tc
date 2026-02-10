#include <stdio.h>

int DO_003_function1(FILE* fp){
  if(fp){
    return 1;
  }
  return 0;
}

void DO_003_function2(){
  FILE* fp = fopen("test.txt", "r");
  FILE* fp2 = NULL;
  if(DO_003_function1(fp) > 0){
	fp2 = fopen("test.txt", "r");  //@violation DOUBLE_OPEN
    fclose(fp);
  } else {
    /* read file */
	fp2 = fopen("test2.txt", "r");  
    fclose(fp);
  }
  if(fp2) {
	fclose(fp2);
  }
}
