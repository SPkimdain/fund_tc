//@checker DO_NOT_USE_INLINE


class DNUINLINE_001_Class {
public:
  inline DNUINLINE_001_Class() : val(0), val2(0) { //@violation DO_NOT_USE_INLINE
    val3 = val + val2;
  }
  
  DNUINLINE_001_Class(int x) : val(x), val2(0) { //It's ok.
    val3 = val + val2;
  }

  int DNUINLINE_001_fuction(); //It's ok.

private:
  int val;
  int val2;
  int val3;
};


int DNUINLINE_001_Class::DNUINLINE_001_fuction() {
  return val + val2 + val3;
}
