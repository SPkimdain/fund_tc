#include <functional>

/* RL_024 - return local(capture) with lambda case. */

using RL_024_LambdaType = std::function<int(int, int)>;


RL_024_LambdaType RL_024_function() {
  short capture = 10;
  auto&& RL_024_lambda = [&capture](int lhs, int rhs) -> int {
    
    return (capture + lhs) * rhs;
  };

  capture++;

  return RL_024_lambda; //@violation RETURN_LOCAL
}

int RL_024_function2() {

  auto&& lambdaFunc = RL_024_function();

  int retVal = lambdaFunc(10, 20);


  return retVal;
}
