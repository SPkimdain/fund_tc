
/* TOS_004 - constructor */
class TOS_004_Class{
public:
  TOS_004_Class() {
  }
  void accessPtr1(int index) {
    ptr1[index] = 10;
  }

  void accessPtr2(int index) {
    ptr2[index] = 0; 
  }

private:
  int ptr1[10];
  int ptr2[5];
};

void TOS_004_function() {
  TOS_004_Class obj;
  obj.accessPtr1(5);
  obj.accessPtr2(5);	//@violation TYPE_OVERRUN.STATIC
}
