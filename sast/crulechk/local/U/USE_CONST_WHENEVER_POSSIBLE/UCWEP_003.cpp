//@checker USE_CONST_WHENEVER_POSSIBLE

class UCWEP_003_class {
public:
  void setValue(const int v) {
    value = v;
  }
private:
  int value;
};

extern void UCWEP_003_doSomething(UCWEP_003_class* x);
extern UCWEP_003_class* UCWEP_003_getObj();

const char* UCWEP_003_function(const int flag, UCWEP_003_class* obj, UCWEP_003_class* obj2,
  char* sink, 
  char** twoDepth) { //@violation USE_CONST_WHENEVER_POSSIBLE

  if (flag > 5) {
    obj->setValue(10); //safe
  }
  else if (flag > 2) {
    UCWEP_003_doSomething(obj2); //safe
  }

  return sink;
}

