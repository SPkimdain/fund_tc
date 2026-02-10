
/* UDDBC_015 - constructor */

class UDDBC_015_Class {
public:
  UDDBC_015_Class(int idx) : index(idx) {}

  int getIndex() { 
    if(index == 0) {
      return 1;
    }
    else {
      return index;
    }
  }
private:
  int index;
};

void UDDBC_015_function(int index) {
  int ret = 0;
  if(index > -10) {
    UDDBC_015_Class idx(index);
    ret = idx.getIndex();
  }

  int* arr = new int[10];
  if(arr == 0) {
    return;
  }
  arr[ret] = 20; //@violation UNDERRUN.DYNAMIC.BAD_COND
  
  delete[] arr;
}

