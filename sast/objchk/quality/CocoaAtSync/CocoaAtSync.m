#include <Foundation/Foundation.h>
void test(id x) {
  if (!x)
    @synchronized(x) {} // @will-violation
                        // nil value used as mutex
}
void test2() {
  id y = 0;
  @synchronized(y) {} // @violation
                      //uninitialized value used as mutex
}
