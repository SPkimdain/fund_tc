#include <stdlib.h>

/* LM_056 - do-while2 */
struct LM_056_Struct {
  char* str;
};

int LM_056_function2(LM_056_Struct* obj, int size) {
  if(obj->str != 0) {
    char* newBuf = new char[size];
    if(newBuf == 0) {
      return 1;
    }
    obj->str = newBuf;
  }
  return 0;
}


LM_056_Struct LM_056_function3(int index) {
  LM_056_Struct ret;
  ret.str = 0;
  
  do {
    LM_056_function2(&ret, 10);
    index--;
  } while(index < 0);
  
  return ret;
} //It's ok.


void LM_056_function4() {
  int* ptr = new int(10);
} //@violation LEAK.MEMORY
