#include <stdio.h>

int DC_001_function1(FILE* fp){
  if(fp){
    fclose(fp);
    return 1;
  }
  return 0;
}

void DC_001_function2(){
  FILE* fp = fopen("test.txt", "r");
  if(DC_001_function1(fp) > 0){
    fclose(fp);   //@violation DOUBLE_CLOSE
  } else {
 
    fclose(fp);
  }

}
