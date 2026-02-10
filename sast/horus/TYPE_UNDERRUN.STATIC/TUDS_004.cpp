
/* TUDS_004 - constructor */
class TUDS_004_Class{
public:
  TUDS_004_Class() {
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

void TUDS_004_function() {
  TUDS_004_Class obj;
  obj.accessPtr1(5);
  obj.accessPtr2(-1);	//@violation TYPE_UNDERRUN.STATIC
}
