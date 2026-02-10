
/* FNH_012 - class type check */
class FNH_012_Class {
public:
  FNH_012_Class() {}
private:
  int val;
};

void FNH_012_function() {
  FNH_012_Class* obj1 = new FNH_012_Class();
  FNH_012_Class obj2;
  
  delete obj1;
  delete &obj2; //@violation FREE_NON_HEAP
}

