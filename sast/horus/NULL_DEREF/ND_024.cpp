
/* ND_024 - constructor */
class ND_024_Class{
public:
  ND_024_Class() {
    value = 100;
    ptr1 = &value;
    ptr2 = 0;
  }
  void accessPtr1(int value) {
    *ptr1 = value;
  }

  void accessPtr2(int value) {
    *ptr2 = value; 
  }

private:
  int value;
  int* ptr1;
  int* ptr2;
};

void ND_024_function() {
  ND_024_Class obj;
  obj.accessPtr1(10);
  obj.accessPtr2(20);	//@violation NULL_DEREF
}
