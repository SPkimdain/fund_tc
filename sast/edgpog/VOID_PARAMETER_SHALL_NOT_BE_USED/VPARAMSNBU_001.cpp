//@checker VOID_PARAMETER_SHALL_NOT_BE_USED


int VPARAMSNBU_001(void wtf) { //@violation VOID_PARAMETER_SHALL_NOT_BE_USED
  int ret = 10;
  
  return ret + 20;
}
