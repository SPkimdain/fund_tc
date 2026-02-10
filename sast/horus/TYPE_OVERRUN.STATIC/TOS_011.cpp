
/* TOS_011 - constructor, initializer list */
class TOS_011_Class{
public:
  TOS_011_Class() : index(5) {}
  void accessPtr1(int value) {
    ptr1[index] = value;
  }

  void accessPtr2(int value) {
    ptr2[index] = value; 
  }

private:
  int index;
  int ptr1[10];
  int ptr2[5];
};

void TOS_025_function() {
  TOS_011_Class obj;
  obj.accessPtr1(50);
  obj.accessPtr2(60);	//@violation TYPE_OVERRUN.STATIC
}
