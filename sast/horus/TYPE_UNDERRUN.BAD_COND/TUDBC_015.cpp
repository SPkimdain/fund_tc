
/* TUDBC_015 - constructor */

class TUDBC_015_Class {
public:
  TUDBC_015_Class(int idx) : index(idx) {}

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

struct TUDBC_015_Struct {
  int arr[10];
};

void TUDBC_015_function(int index) {
  int ret = 0;
  if(index > -10) {
    TUDBC_015_Class idx(index);
    ret = idx.getIndex();
  }

  TUDBC_015_Struct obj;
  obj.arr[ret] = 20; //@violation TYPE_UNDERRUN.BAD_COND
}

