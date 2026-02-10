#include <stdlib.h>
#include <memory.h>

/* ODI_025 - memcpy complex */
struct ODI_025_Struct {
  int size;
  int* arr;
};

class ODI_025_class {
public:
  ODI_025_class() : switchVal(false), switchVal2(false) {}

  void setSwitchVal(bool s) {
    switchVal = s;
  }

  void setSwitchVal2(bool s) {
    switchVal2 = s;
  }
  int copyObj(ODI_025_Struct* obj, bool checkMin, bool check2) {
    if(obj == 0 || check2 == false) {
      return 0;
    }
    
    if(switchVal == false || switchVal2 == false) {
      return 0;
    }

    return copyObjAux(obj, checkMin);
  }

private:

  void* copyVal(void** data, int oldSize, int newSize, bool checkMin) {
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

  int copyObjAux(ODI_025_Struct* obj, bool checkMin) {
    if(obj == 0) {
      return 0;
    }

    obj->arr = (int*)copyVal((void**)&obj->arr,
      sizeof(int*) * obj->size, 2 * sizeof(int*) * obj->size, checkMin);

    obj->size = 2 * obj->size;

    return 1;
  }


private:
  bool switchVal;
  bool switchVal2;
};

void ODI_025_function4(int lhs, int rhs) {
  ODI_025_Struct obj;
  obj.size = 1024;
  obj.arr = (int*)calloc(1024, sizeof(int));

  if(obj.arr == 0) {
    return;
  }

  ODI_025_Struct obj2;
  obj2.size = 1024;
  obj2.arr = (int*)calloc(1024, sizeof(int));

  if(obj2.arr == 0) {
    free(obj.arr);
    return;
  }

  bool flag = true;
  if(lhs < 0 || rhs < 0) {
    lhs = 10;
    rhs = 20;
  }
  else {
    lhs = 50;
  }
 
  if(lhs + rhs > 0) {
    if(lhs * rhs > 0) {

      flag = false;

      ODI_025_class util;

      util.copyObj(&obj, true, true); //It's ok.

      util.copyObj(&obj2, flag, false); //It's ok.
            
      util.copyObj(&obj2, flag, true); //It's ok.

      util.setSwitchVal(true);

      bool ret = util.copyObj(&obj2, flag, true); //It's ok.

      util.setSwitchVal2(true);

      util.copyObj(&obj2, flag, true); //@violation OVERRUN.DYNAMIC.IN_FUNC_CALL
    }
  }  

  free(obj.arr);
  
  free(obj2.arr);

  return;
}
