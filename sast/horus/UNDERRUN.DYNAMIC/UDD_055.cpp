#include <string.h>
#include <stdlib.h>

/* UDD_055 - a loop variable */
void UDD_055_function1(int fw) {
  int maxloc = 0;  
  if(fw < 0) {
    return;
  }
  int* fad = (int*)calloc(1, 50 * sizeof(int));
  if(fad == 0) {
    return;
  }

  int ret = 0;
  int test = 0;
  
  for(int j = 0; j < fw; j++) {
    test++;
    if(j < maxloc) {	//j >= 0이고, maxloc == 0이다. 따라서 들어갈 수 없는 branch이다.
      ret += fad[j]; //It's ok.
    }    
    test--;
  }
  
  free(fad);
}


 void UDD_055_function2() {
   char *dest;
   dest = (char*)malloc(12);
  
   if(dest == 0) {
     return;
   }
  
   (dest + 3)[-4] = 'x'; //@violation UNDERRUN.DYNAMIC
   free(dest);
 }
