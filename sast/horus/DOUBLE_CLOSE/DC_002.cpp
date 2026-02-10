#include <stdio.h>

/* DC_002 - lambda case. */

int DC_002_function1(FILE* fp){
  if(fp){
    fclose(fp);
    return 1;
  }
  return 0;
}

void DC_002_function2(){
  auto&& DC_002_lambda = [](FILE* fp) {
    fclose(fp);
    return;
  };

  FILE* fp = fopen("test.txt", "r");
  if(DC_002_function1(fp) > 0){
    DC_002_lambda(fp); //@violation DOUBLE_CLOSE
  } else {
 
    fclose(fp);
  }

}
