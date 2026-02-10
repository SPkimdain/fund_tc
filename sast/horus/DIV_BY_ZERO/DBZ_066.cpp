
/* DBZ_066 - divide by zero with lambda case3 */
#include <functional>

using DBZ_066_LambdaFuncType = std::function<int(int)>;


int DBZ_066_function() {
  int x = 5;
  int y = 10;
  auto&& lambda = [x, &y](int a) {
    return a - x - y;
  };

  int ret1 = lambda(10);

  auto&& lambda2 = lambda;

  y = 1;

  int ret2 = lambda2(10);

  DBZ_066_LambdaFuncType lft = lambda;

  y = 5;

  int ret3 = lft(10);

  int div1 = 10000 / ret1; //It's ok. ret1 is -5.
  int div2 = 10000 / ret2; //It's ok. ret2 is 6
  int div3 = 10000 / ret3; //@violation DIV_BY_ZERO

  return 0;
}
