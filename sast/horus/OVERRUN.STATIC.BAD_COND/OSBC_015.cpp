
/* OSBC_015 - constructor */

class OSBC_015_Class {
public:
  OSBC_015_Class(unsigned idx) : index(idx) {}

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

void OSBC_015_function(unsigned index) {
  int ret = 0;
  if(index < 15) {
    OSBC_015_Class idx(index);
    ret = idx.getIndex();
  }

  int arr[10];
  arr[ret] = 20; //@violation OVERRUN.STATIC.BAD_COND
}

