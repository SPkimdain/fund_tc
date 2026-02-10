

/* ODBC_014 - Field index */
class ODBC_014_Class {
public:
  ODBC_014_Class() : arr(0), index(0) {
    arr = new int[10];
    int* temp = new int[20];
    if(temp != 0) {
      delete[] temp;
    }
  }
  ~ODBC_014_Class() {
    if(arr != 0) {
      delete[] arr;
    }
  }

  void setIndex(unsigned idx) {
    index = idx;
  }
  void accessArray() {
    if(arr != 0) {
      arr[index] = 5;
    }
  }
private:
  int* arr;
  unsigned index;
};

void ODBC_014_function(unsigned index) {
  ODBC_014_Class target;

  if(index < 5) {
    target.setIndex(index);
  }
  else if(index < 15) {
    target.setIndex(index);
  }
  else {}

  target.accessArray(); //@violation OVERRUN.DYNAMIC.BAD_COND
}
