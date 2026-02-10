#include <stdlib.h>
#include <functional>

/* DF_020 - double free with lambda. */

using DF_020_LambdaType = std::function<void(int*)>;


DF_020_LambdaType DF_020_function1() {
  auto&& lambda = [](int* ptr) {
    free(ptr);
  };

  return lambda;
}

int DF_020_function2(int flag) {
  int * ptr = (int*)malloc(4); 

  auto&& DF_020_lambda_obj = DF_020_function1();

  DF_020_lambda_obj(ptr);

  DF_020_lambda_obj(ptr); //@violation DOUBLE_FREE
  return flag;
} 
