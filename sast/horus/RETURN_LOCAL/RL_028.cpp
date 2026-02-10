#include <functional>

/* RL_028 - return local(capture) with lambda case2. */

using RL_028_LambdaType = std::function<int(int, int)>;


RL_028_LambdaType RL_028_function() {
  short capture = 10;
  short* wrapper = &capture;

  auto&& RL_028_lambda = [wrapper](int lhs, int rhs) -> int {
    
    return (*wrapper + lhs) * rhs;
  };

  capture++;

  return RL_028_lambda; //@violation RETURN_LOCAL
}

int RL_028_function2() {

  auto&& lambdaFunc = RL_028_function();

  int retVal = lambdaFunc(10, 20);


  return retVal;
}
