

/* TOBC_014 - Field index */
class TOBC_014_Class {
public:
  TOBC_014_Class() : index(0) {}

  void setIndex(unsigned idx) {
    index = idx;
  }
  void accessArray() {
    arr[index] = 5;
  }
private:
  int arr[10];
  unsigned index;
};

void TOBC_014_function(unsigned index) {
  TOBC_014_Class target;

  if(index < 5) {
    target.setIndex(index);
  }
  else if(index < 15) {
    target.setIndex(index);
  }
  else {}

  target.accessArray(); //@violation TYPE_OVERRUN.BAD_COND
}
