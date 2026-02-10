
/* ND_051 - template class */
template<typename T>
class ND_051_Class {
public:
  ND_051_Class(T arg) {
    value = arg;
  }
  void doSomething() {
    *value = 100; 
  }
private:
  T value;
};

void ND_051_function() {
  int v = 1000;
  ND_051_Class<int*> obj(&v);
  obj.doSomething(); //It's ok.

  ND_051_Class<int*> obj2(0);
  obj2.doSomething();	//@violation NULL_DEREF
}

