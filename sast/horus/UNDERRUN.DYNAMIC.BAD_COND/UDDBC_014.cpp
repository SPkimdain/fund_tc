

/* UDDBC_014 - Field index */
class UDDBC_014_Class {
public:
  UDDBC_014_Class() : arr(0), index(0) {
    arr = new int[10];
    int* temp = new int[20];
    if(temp != 0) {
      delete[] temp;
    }
  }
  ~UDDBC_014_Class() {
    if(arr != 0) {
      delete[] arr;
    }
  }

  void setIndex(int idx) {
    index = idx;
  }
  void accessArray() {
    if(arr != 0) {
      arr[index] = 5;
    }
  }
private:
  int* arr;
  int index;
};

void UDDBC_014_function(int index) {
  UDDBC_014_Class target;

  if(index >= 0) { // [0, max]
    target.setIndex(index - 1);
  }

  target.accessArray(); //@violation UNDERRUN.DYNAMIC.BAD_COND
}
