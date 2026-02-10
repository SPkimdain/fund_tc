
/* LM_026 - destructor */
class LM_026_Class{
public:
  LM_026_Class(int* _ptr1, int* _ptr2) {
    ptr1 = _ptr1;
    ptr2 = _ptr2;
  }
  ~LM_026_Class() {
    //ptr1 is leaked.
    delete ptr2;    
  }
  
private:
  int* ptr1;
  int* ptr2;
};

void LM_026_function(bool flag) {
  if(flag == true) {
    LM_026_Class* obj = new LM_026_Class(new int(5), new int(10));
    delete obj; 
  }
} //@violation LEAK.MEMORY

