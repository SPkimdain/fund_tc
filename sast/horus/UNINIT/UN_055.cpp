
/* UN_055 - template initializer list */
template<typename T>
class UN_055_Class {
public:
  UN_055_Class(T arg) {} //Missing init.

  int doSomething() {
    int ret = value * 10;
    return ret;
  }

private:
  mutable T value;
};

void UN_055_function() {
  UN_055_Class<int> obj(10);
  int retValue = obj.doSomething(); //@violation UNINIT
}



