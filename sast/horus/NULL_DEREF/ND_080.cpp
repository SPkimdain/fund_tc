#include <functional>


/* ND_080 - null dereference with lambda. */

using ND_080_LambdaType = std::function<int*(int*)>;

ND_080_LambdaType ND_080_function1(int flag) {
  auto&& ND_080_lambda1 = [](int* ptr) {
    if(ptr != 0) {
      *ptr = 10;
    }
    return ptr;
  };

  auto&& ND_080_lambda2 = [](int* ptr) {
    *ptr = 10;
    return ptr;
  };

  if(flag > 10) {
    return ND_080_lambda1;
  }
  else {
    return ND_080_lambda2;
  }
}


void ND_080_function2() {
  int* p = 0;

  ND_080_LambdaType lambdaSafe = ND_080_function1(20);
  int* ret = lambdaSafe(p); //It's ok.

  ND_080_LambdaType lambdaND = ND_080_function1(5);
  int* ret2 = lambdaND(0); //@violation NULL_DEREF
}
