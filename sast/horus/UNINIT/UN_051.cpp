#pragma warning(disable : 4700)

/* UN_051 - template class */
template<typename T>
class UN_051_Class {
public:
  UN_051_Class(T& arg) {
    value = arg; 
  }

private:
  T value;
};

void UN_051_function() {
  int v = 1000;
  int v2;
  UN_051_Class<int> obj(v); //It's ok

  UN_051_Class<int> obj2(v2); //@violation UNINIT
}

