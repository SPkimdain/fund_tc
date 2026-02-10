
/* ODBC_015 - constructor */

class ODBC_015_Class {
public:
  ODBC_015_Class(unsigned idx) : index(idx) {}

  unsigned getIndex() { 
    if(index == 0) {
      return 1;
    }
    else {
      return index;
    }
  }
private:
  unsigned index;
};

void ODBC_015_function(unsigned index) {
  int ret = 0;
  if(index < 15) {
    ODBC_015_Class idx(index);
    ret = idx.getIndex();
  }

  int* arr = new int[10];
  if(arr == 0) {
    return;
  }
  arr[ret] = 20; //@violation OVERRUN.DYNAMIC.BAD_COND
  
  delete[] arr;
}

