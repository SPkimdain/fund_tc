//@checker INFORMATION_LEAK
#include <stdio.h>
#include <stdlib.h>

void IL_001_function(){
  char* path = getenv("PATH");
  fprintf(stderr, path); //@violation INFORMATION_LEAK
}

