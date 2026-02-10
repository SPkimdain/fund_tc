/* PMFE_006 - log, log10, log2 */

/* Since C++11 */
extern double log(double x);
extern double log10(double x);
extern double log2(double x);

class PMFE_006_Class {
public:
  PMFE_006_Class(double x) : val(x) {}

  double getValue() { return val; }

private:
  double val;
};

void PMFE_006_function() {
  PMFE_006_Class obj(10.3F);
  PMFE_006_Class obj2(0.0F);
  PMFE_006_Class obj3(-3.4F);

  double ret = 0.F;
  ret += log(obj.getValue()); //It's ok.
  
  ret += log10(obj2.getValue()); //It's ok.

  ret += log2(obj3.getValue()); //@violation PREVENT_MATH_FUNCTIONS_ERROR
}
