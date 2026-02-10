
/* TOBC_015 - constructor */

class TOBC_015_Class {
public:
  TOBC_015_Class(unsigned idx) : index(idx) {}

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

struct TOBC_015_Struct {
  int arr[10];
};

void TOBC_015_function(unsigned index) {
  int ret = 0;
  if(index < 15) {
    TOBC_015_Class idx(index);
    ret = idx.getIndex();
  }

  TOBC_015_Struct obj;
  obj.arr[ret] = 20; //@violation TYPE_OVERRUN.BAD_COND
}

