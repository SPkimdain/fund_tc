

/* OSBC_014 - Field index */
class OSBC_014_Class {
public:
  OSBC_014_Class() : index(0) {}

  void setIndex(unsigned idx) {
    index = idx;
  }
  void accessArray() {
    int arr[10] = { 0, };
    arr[index] = 5;
  }
private:
  unsigned index;
};

void OSBC_014_function(unsigned index) {
  OSBC_014_Class target;

  if(index < 5) {
    target.setIndex(index);
  }
  else if(index < 15) {
    target.setIndex(index);
  }
  else {}

  target.accessArray(); //@violation OVERRUN.STATIC.BAD_COND
}
