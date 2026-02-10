
/* UAF_024 - constructor */
class UAF_024_Class{
public:
  UAF_024_Class() {
    ptr1 = new int();
    ptr2 = new int();
  }
  ~UAF_024_Class() {
    delete ptr1;
  }

  void releasePtr2() {
    delete ptr2;
  }

  void accessPtr1(int value) {
    *ptr1 = value;
  }

  void accessPtr2(int value) {
    *ptr2 = value; // USE_AFTER_FREE
  }

private:
  int* ptr1;
  int* ptr2;
};

void UAF_024_function() {
  UAF_024_Class obj;
  obj.accessPtr1(10); //It's ok.

  obj.releasePtr2();
  obj.accessPtr2(20); //@violation USE_AFTER_FREE
}
