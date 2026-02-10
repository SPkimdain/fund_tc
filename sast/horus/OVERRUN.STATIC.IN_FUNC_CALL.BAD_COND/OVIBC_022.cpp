#include <stdlib.h>
#include <memory.h>
#include <time.h>
#include <string.h>

/* OVIBC_022 - strcat2 */
void OVIBC_022_function1(int flag, int size){
  char fromline[40] = "From movemail ";
  time_t now;
  struct tm* ltime;
  now = time(0);
  ltime = localtime(&now);
  strcat(fromline, asctime(ltime)); //It's ok.
  
  char* src = "asd"; //sizeof(src) == 4
  char* src2 = "abcd"; //sizeof(src2) == 5
  char dst[4] = { 0, };

   if(size >= 0) {
     if(flag > 0) {
     }
     else {
       if(size < 6) {
         memcpy(dst, src2, size); //@violation OVERRUN.STATIC.IN_FUNC_CALL.BAD_COND
       }
     }
   } 
}
