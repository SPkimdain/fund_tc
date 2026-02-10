
/* LM_047 - template initializer list. */
template<typename T>
class LM_047_Class {
public:
  LM_047_Class(T* arg) : value(arg) {}

  T* getValue() { return value; }

private:
  mutable T* value;
};


char* LM_047_function(int flag) {
  char* val = new char('x');
  LM_047_Class<char> obj(val);

  if(flag > 0) {
    return obj.getValue();
  }
  else {
    return 0;
  } //@violation LEAK.MEMORY
}

