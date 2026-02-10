#include <stdio.h>

void UAC_001_function(){
  FILE* fp = fopen("test.txt", "r");
  fclose(fp);
  fprintf(fp, "Hello"); //@violation USE_AFTER_CLOSE.EXT
}

