

/* TUDBC_014 - Field index */
class TUDBC_014_Class {
public:
  TUDBC_014_Class() : index(0) {}

  void setIndex(int idx) {
    index = idx;
  }
  void accessArray() {
    arr[index] = 5;
  }
private:
  int arr[10];
  int index;
};

void TUDBC_014_function(int index) {
  TUDBC_014_Class target;

  if(index >= 0) { //[0, max]
    target.setIndex(index - 1);
  }

  target.accessArray(); //@violation TYPE_UNDERRUN.BAD_COND
}
