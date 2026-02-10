#include <stdio.h>
#include <string.h>


/* TUDS_056 - fgets return, empty string. */
struct TUDS_056_Struct{
  char a[100];
};

void TUDS_056_function1(TUDS_056_Struct& tos, int index){
  tos.a[index - 1] = '\0';
}

void TUDS_056_function2(){
  TUDS_056_Struct tos;

  if(fgets(tos.a, sizeof(tos.a), stdin) == NULL) {
    return;
  }

  TUDS_056_function1(tos, strlen(tos.a)); //@violation TYPE_UNDERRUN.STATIC
}
