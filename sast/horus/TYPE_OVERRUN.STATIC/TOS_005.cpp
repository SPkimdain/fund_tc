
/* TOS_005 - destructor */
class TOS_005_Class{
public:
  TOS_005_Class() : index(0), ptr() {}
  ~TOS_005_Class() {
    ptr[index] = 0; 
  }
  
  void setIndex(int x) {
    index = x;
  }
  
  void accessPtr1(int value) {
    ptr[0] = value;
  }

private:
  int index;
  int ptr[10];
};

void TOS_005_function() {
  TOS_005_Class* obj = new TOS_005_Class;
  obj->setIndex(20);
  delete obj;	//@violation TYPE_OVERRUN.STATIC
}
