
/* OV_051 - template class */
template<typename T>
class OV_051_Class {
public:
  OV_051_Class(T arg) {
    value = arg;
  }
  void doSomething(int index) {
    *(value + index) = 100;
  }
private:
  T value;
};

void OV_051_function() {
  int arr[10] = { 0, };
  OV_051_Class<int*> obj(arr);
  obj.doSomething(3); //It's ok.

  OV_051_Class<int*> obj2(arr);
  obj2.doSomething(12);  //@violation OVERRUN.STATIC
}

