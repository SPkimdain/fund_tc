#include <stdlib.h>
#include <memory.h>

/* ODI_024 - memcpy */
struct ODI_024_Struct {
  int size;
  int* arr;
};

void* ODI_024_function1(void** data, int oldSize, int newSize, bool checkMin) {
  void* inData = *data;
  void* newData = (void*)calloc(1, newSize);
  if(newData == 0) {
    return inData;
  }
  
  int minSize = 0;
  
  if(checkMin == true) {
    minSize = oldSize < newSize ? oldSize : newSize;
  }
  else {
    /* wrong compare */
    minSize = oldSize < newSize ? newSize : oldSize;
  }
  
  memcpy((char*)newData, (char*)inData, minSize);
  free(inData);
  *data = 0;
  return newData;
}

int ODI_024_function2(ODI_024_Struct* obj, bool checkMin) {
  if(obj == 0) {
    return 0;
  }

  obj->arr = (int*)ODI_024_function1((void**)&obj->arr,
    sizeof(int*) * obj->size, 2 * sizeof(int*) * obj->size, checkMin);
    
  obj->size = 2 * obj->size;
  
  return 1;
}

void ODI_024_function4() {
  ODI_024_Struct obj;
  obj.size = 1024;
  obj.arr = (int*)calloc(1024, sizeof(int));

  if(obj.arr == 0) {
    return;
  }
  
  ODI_024_function2(&obj, true); //It's ok.

  free(obj.arr);
  
  return;
}

void ODI_024_function5(unsigned int x, int y){
  ODI_024_Struct obj;
  obj.size = 1024;
  obj.arr = (int*)calloc(1024, sizeof(int));

  if(obj.arr == 0) {
    return;
  }

  ODI_024_function2(&obj, false); //@violation OVERRUN.DYNAMIC.IN_FUNC_CALL

  free(obj.arr);

  return;
}
