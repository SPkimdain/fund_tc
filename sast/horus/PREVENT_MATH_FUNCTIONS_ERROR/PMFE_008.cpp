/* PMFE_008 - ilogb */

/* Since C++11 */
extern double ilogb(double x);

template<typename T>
class PMFE_008_Class {
public:
  PMFE_008_Class(T arg) : value(arg) {}

  T getValue() { return value; }

private:
  mutable T value;
};


int PMFE_008_function2(int value) {
  PMFE_008_Class<short> obj(0);
  
  double val = obj.getValue();
  double ret = ilogb(val + 5); //It's ok.


  double ret2 = ilogb(val); //@violation PREVENT_MATH_FUNCTIONS_ERROR

  return 0;
}

