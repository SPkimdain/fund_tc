#include <stdlib.h>
#include <functional>

/* LM_079 -leak memory with lambda. */

using LM_079_LambdaType = std::function<int*(int)>;

LM_079_LambdaType LM_079_function() {

  auto&& LM_079_lambda = [](int size) {
    int* buf = (int*)malloc(size * sizeof(int));

    return buf;
  };


  return LM_079_lambda;
} 


void LM_079_function2(int flag) {
  int ret = 0;
  auto&& allocator = LM_079_function();

  if(flag > 10) {
    int* buffer = allocator(10);

    ret++;
  } 

} //@violation LEAK.MEMORY
