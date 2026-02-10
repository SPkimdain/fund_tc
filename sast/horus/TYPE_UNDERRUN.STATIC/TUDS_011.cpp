
/* TUDS_011 - constructor, initializer list */
class TUDS_011_Class{
public:
  TUDS_011_Class() : index(-1) {}
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

void TUDS_025_function() {
  TUDS_011_Class obj;
  obj.accessPtr2(60);	//@violation TYPE_UNDERRUN.STATIC
}
