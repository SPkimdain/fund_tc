
/* TUDS_005 - destructor */
class TUDS_005_Class{
public:
  TUDS_005_Class() : index(0), ptr() {}
  ~TUDS_005_Class() {
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

void TUDS_005_function() {
  TUDS_005_Class* obj = new TUDS_005_Class;
  obj->setIndex(-1);
  delete obj;	//@violation TYPE_UNDERRUN.STATIC
}
