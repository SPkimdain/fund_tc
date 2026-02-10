
/* ND_025 - constructor, initializer list */
class ND_025_Class{
public:
  ND_025_Class() : value(100), ptr1(&value), ptr2(0) {}
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

void ND_025_function() {
  ND_025_Class obj;
  obj.accessPtr1(10);
  obj.accessPtr2(20);	//@violation NULL_DEREF
}
