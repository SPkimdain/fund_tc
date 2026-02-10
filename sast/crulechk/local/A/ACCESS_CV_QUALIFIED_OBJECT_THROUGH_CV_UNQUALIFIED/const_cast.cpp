//@checker ACCESS_CV_QUALIFIED_OBJECT_THROUGH_CV_UNQUALIFIED
#include <iostream>

void acvqotcu_01_function(const int &ci) {
  int &ir = const_cast<int &>(ci); //@violation ACCESS_CV_QUALIFIED_OBJECT_THROUGH_CV_UNQUALIFIED
  ir = 42;
}

void acvqotcu_01_function2(int &ci) {
    ci = 42;
}

int acvqotcu_01_functio3() {
    const int i = 4;
    int j = 4;
    short s;
    volatile int *v = &j;

    s = static_cast<short>(i);
    s = (short)i;
    *(const_cast<int *>(v)) = 24; //@violation ACCESS_CV_QUALIFIED_OBJECT_THROUGH_CV_UNQUALIFIED

    acvqotcu_01_function(i);
    acvqotcu_01_function2(j);
    return 1;
}
