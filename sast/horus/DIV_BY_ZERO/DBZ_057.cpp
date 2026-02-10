
/* DBZ_057 - template initializer list */

template<typename T>
class DBZ_057_Class {
public:
  DBZ_057_Class(T arg) : value(arg) {}

  T getValue() { return value; }

private:
  mutable T value;
};


int DBZ_057_function2(int value) {
  DBZ_057_Class<short> obj(0);

  int ret = value / obj.getValue(); //@violation DIV_BY_ZERO

  return ret;
}

