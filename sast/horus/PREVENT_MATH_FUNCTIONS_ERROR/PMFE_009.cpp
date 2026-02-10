
/* PMFE_009 - logb */

/* Since C++11 */
extern double logb(double x);

struct PMFE_009_Struct1 {
  char flag;
  int value;
};

struct PMFE_009_Struct2 {
  PMFE_009_Struct1 ndObj1;
};

struct PMFE_009_Struct3{
  PMFE_009_Struct2 ndObj2;
};

int PMFE_009_function(int flag) {
  int v = 1053;
  PMFE_009_Struct3 obj;
  if(flag > 10) {
    obj.ndObj2.ndObj1.value = 1000; //This flow is a problem.
  }
  else {
    obj.ndObj2.ndObj1.value = v;
  }

  double b = (obj.ndObj2.ndObj1.value % 10); //It's 0.F;
  
  return static_cast<int>(logb(b)); //@violation PREVENT_MATH_FUNCTIONS_ERROR
}

