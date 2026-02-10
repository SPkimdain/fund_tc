
/* DF_010 - destructor */
class DF_010_Class {
public:
  DF_010_Class(int* arg) {
    value = arg;
  }

  ~DF_010_Class() {
    delete value;
  }

private:
  int* value;
};

void DF_010_function(bool flag) {
  int* x = new int(50);
  if(flag == true) {
    DF_010_Class obj(x);
  } // x is released.
  delete x; //@violation DOUBLE_FREE
}
