#include <functional>

/* SN_011 - shift case with lambda. */

using SN_011_LambdaType = std::function<int(int)>;

SN_011_LambdaType SN_011_function1() {
  int x = 10;
  int y = -10;

  auto&& SN_011_lambda = [x, y](int flag) {
    if(flag > 10) {
      return x;
    }
    else {
      return y;
    }
  };

  return SN_011_lambda;
}

SN_011_LambdaType SN_011_function2() {
  auto&& SN_011_lambda2 = [](int flag) {
    return flag;
  };

  return SN_011_lambda2;
}


unsigned SN_011_function3() {
  unsigned int p = 10;

  SN_011_LambdaType lmb2 = SN_011_function2();

  SN_011_LambdaType lmb1 = SN_011_function1();

  int lambdaRet1 = lmb1(20);
  int lambdaRet2 = lmb1(5);
  unsigned int ret1 = p << lambdaRet1; //It's ok.

  unsigned int ret2 = p << lambdaRet2; //@violation SHIFT_NEGATIVE  

  unsigned int ret3 = p << lmb2(10); //It's ok.

  return ret1 + ret2;
}
