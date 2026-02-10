//@checker DO_NOT_USE_OFFSETOF_MACRO
#define offsetof(TYPE, MEMBER) __builtin_offsetof (TYPE, MEMBER)

struct DNUOFFSETOFM_001_Class {
  int val;
  float val2;
  double val3;
};


void DNUOFFSETOFM_001_function() {
  DNUOFFSETOFM_001_Class obj;

  int ret = offsetof(DNUOFFSETOFM_001_Class, val2); //@violation DO_NOT_USE_OFFSETOF_MACRO

}
