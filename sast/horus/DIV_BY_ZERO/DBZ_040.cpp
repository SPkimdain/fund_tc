#include <memory.h>

/* DBZ_040 - int_calc from opus */
void DBZ_040_function1(int x) {
  int y = x - x;
  int ret = 100 / y; //@violation DIV_BY_ZERO
}
