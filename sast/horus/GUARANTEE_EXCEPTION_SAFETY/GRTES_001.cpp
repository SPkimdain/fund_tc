#include <memory.h>
#include <exception>>
#include <iostream>

/* GRTES_001 - simple case 1 */

class GRTES_001_Class {
public:
  
  GRTES_001_Class& operator=(const GRTES_001_Class& rhs) {
    if(this != &rhs) {
      delete[] arr;
      arr = nullptr;
      size = rhs.size;
      if(size) {
        arr = new int[size]; //@violation GUARANTEE_EXCEPTION_SAFETY
        memcpy(arr, rhs.arr, size * sizeof(*arr));
      }
    }

    return *this;
  }

  GRTES_001_Class safe(const GRTES_001_Class& rhs) {
    int* tmp = nullptr;
    if(this != &rhs) {      
      if(rhs.size) {
        arr = new int[size]; //It's ok.
        memcpy(arr, rhs.arr, size * sizeof(*arr));
      }
    }
    delete[] arr;
    arr = tmp;
    size = rhs.size;

    return *this;
  }

  GRTES_001_Class& safe2(const GRTES_001_Class& rhs) {
    if(this != &rhs) {
      delete[] arr;
      arr = nullptr;
      size = rhs.size;
      if(size) {
        try {
          arr = new int[size]; //It's ok.
          memcpy(arr, rhs.arr, size * sizeof(*arr));
        }
        catch(std::exception& ex) {
          std::cout << ex.what();
        }
      }
    }

    return *this;
  }

private:
  int* arr;
  int size;
};


