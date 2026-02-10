
/* LM_024 - constructor */
class LM_024_Class{
public:
  LM_024_Class(int* _ptr1) {
    ptr1 = _ptr1;
  }
  ~LM_024_Class() {
    delete ptr1;
  }
  
  void accessPtr1(int value) {
    *ptr1 = value;
  }
  
private:
  int* ptr1;
};

void LM_024_function(bool flag) {
  if(flag == true) {
    int* x = new int(50);
    int* y = new int(100);
    LM_024_Class obj(x);
    obj.accessPtr1(10); //It's ok.
    //x is released by destructor.
    //y is leaked.
   } 
} //@violation LEAK.MEMORY
