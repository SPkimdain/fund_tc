
/* UDSBC_015 - constructor */

class UDSBC_015_Class {
public:
  UDSBC_015_Class(int idx) : index(idx) {}

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

void UDSBC_015_function(int index) {
  int ret = 0;
  if(index > -10) {
    UDSBC_015_Class idx(index);
    ret = idx.getIndex();
  }

  int arr[10];
  arr[ret] = 20; //@violation UNDERRUN.STATIC.BAD_COND
}

