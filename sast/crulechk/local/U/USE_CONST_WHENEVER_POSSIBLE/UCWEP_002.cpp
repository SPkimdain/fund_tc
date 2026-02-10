//@checker USE_CONST_WHENEVER_POSSIBLE

class UCWEP_002_class {
public:
  void setValue(const int v) {
    value = v;
  }
private:
  int value;
};

extern void UCWEP_002_doSomething(int* x);

int UCWEP_002_function(const int flag, UCWEP_002_class* sink) { //@violation USE_CONST_WHENEVER_POSSIBLE

  return 1;
}

