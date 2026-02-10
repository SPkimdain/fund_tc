#include <CoreFoundation/CoreFoundation.h>
void test() {
  CFArrayRef A = CFArrayCreate(0, 0, 0, &kCFTypeArrayCallBacks);
  CFArrayGetValueAtIndex(A, 0); // @violation
  //Checks for index out-of-bounds when using CFArray API.
}
