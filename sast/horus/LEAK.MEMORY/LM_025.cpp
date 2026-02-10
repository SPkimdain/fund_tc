
/* LM_025 - constructor, initializer list */
class LM_025_Class{
public:
  LM_025_Class(int* arg1) : ptr1(arg1) {}
  ~LM_025_Class() {
    delete ptr1;
  }
  
  void accessPtr1(int value) {
    *ptr1 = value;
  }
  
private:
  int* ptr1;
};

void LM_025_function(bool flag) {
  if(flag == true) {
    int* x = new int(10);
    int* y = new int(20);
    LM_025_Class obj(x);
    obj.accessPtr1(1);
    //x is released by destructor.
    //y is leaked.
  } 
} //@violation LEAK.MEMORY
