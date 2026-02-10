
/* CAV_023 - template initializer list */

template<typename T>
class CAV_023_Class {
public:
  CAV_023_Class(T arg) : value(arg) {}

  T getValue() { return value; }

private:
  mutable T value;
};

void CAV_023_function() {
  CAV_023_Class<int> obj(100000);
  short x = 0;
  x = obj.getValue(); //@violation CAST_ALTERS_VALUE.EXT
}

