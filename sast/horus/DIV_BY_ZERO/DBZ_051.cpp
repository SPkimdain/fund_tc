
/* DBZ_051 - template class */
template<typename T>
class DBZ_051_Class {
public:
  DBZ_051_Class(T arg) {
    value = arg;
  }
  void doSomething() {
    int ret = 10000 / value; // DIV_BY_ZERO
  }
private:
  T value;
};

void DBZ_051_function() {
  int v = 1000;
  DBZ_051_Class<int> obj(v);
  obj.doSomething(); //It's ok.

  DBZ_051_Class<int> obj2(0);
  obj2.doSomething(); //@violation DIV_BY_ZERO
}

