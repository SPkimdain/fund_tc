#include <dispatch/dispatch.h>

dispatch_once_t pred2 = 0;
dispatch_once_t *pred3 = 0;

void test4() {
  dispatch_once(pred3, ^(){});
}

void test() {
  static dispatch_once_t acam = 0;
  dispatch_once(&acam, ^(){});
}

void test2() {
  dispatch_once(&pred2, ^(){});
}

void test3() {
  dispatch_once_t pred = 0;
  dispatch_once(&pred, ^(){}); // @violation
                                //: dispatch_once uses local
}
