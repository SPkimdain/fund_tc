#include <CoreFoundation/CoreFoundation.h>
void test(CFErrorRef *error) {  //@violation
  // function accepting CFErrorRef* should have a non-void return
}
int foo(CFErrorRef *error) {
  *error = 0; // @will-violation: potential null dereference
  return 0;
}

int bar(CFErrorRef *error) {
   return 0;
}