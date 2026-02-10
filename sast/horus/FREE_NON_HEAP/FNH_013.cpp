
/* FNH_013 - class type with multiple new in the expression */
class FNH_013_Class {
public:
  FNH_013_Class(int* v) {
    val = v;
  }
  ~FNH_013_Class() {
    if(val != 0) {
      delete val;
    }
  }
private:
  int* val;
};

void FNH_013_function() {
  FNH_013_Class* obj1 = new FNH_013_Class(new int(2));
  FNH_013_Class obj2(new int(3));
  
  delete obj1;
  delete &obj2; //@violation FREE_NON_HEAP
}

