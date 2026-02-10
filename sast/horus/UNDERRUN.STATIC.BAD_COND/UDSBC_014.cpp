

/* UDSBC_014 - Field index */
class UDSBC_014_Class {
public:
  UDSBC_014_Class() : index(0) {}

  void setIndex(int idx) {
    index = idx;
  }
  void accessArray() {
    int arr[10] = { 0, };
    arr[index] = 5;
  }
private:
  int index;
};

void UDSBC_014_function(int index) {
  UDSBC_014_Class target;

  if(index > -3 && index < 5) {
    target.setIndex(index);
  }

  target.accessArray(); //@violation UNDERRUN.STATIC.BAD_COND
}
