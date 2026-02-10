
/* ND_026 - destructor */
class ND_026_Class{
public:
  ND_026_Class() : value(100), ptr1(&value), ptr2(0) {}
  ~ND_026_Class() {
    *ptr2 = 0; 
  }
  
  void accessPtr1(int value) {
    *ptr1 = value;
  }

private:
  int value;
  int* ptr1;
  int* ptr2;
};

void ND_026_function() {
  ND_026_Class* obj = new ND_026_Class;
  delete obj;	//@violation NULL_DEREF
}
