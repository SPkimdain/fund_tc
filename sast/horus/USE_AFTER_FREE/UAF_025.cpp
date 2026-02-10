
/* UAF_025 - constructor, initializer list */
class UAF_025_Class{
public:
  UAF_025_Class(int* arg1, int *arg2) : ptr1(arg1), ptr2(arg2) {}
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

void UAF_025_function() {
  int* arg1 = new int(10);
  int* arg2 = new int(20);  
  UAF_025_Class obj(arg1, arg2);

  delete arg2;

  obj.accessPtr1(1);
  obj.accessPtr2(2); //@violation USE_AFTER_FREE

  delete arg1;
}
