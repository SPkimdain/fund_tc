#include <CoreFoundation/CoreFoundation.h>
void test(CFTypeRef p) {
  if (!p)
    CFRetain(p); // @violation
}
void test2(int x, CFTypeRef p) {
  if (p)
    return;

  CFRelease(p); // @violation
}
//Check for null arguments to CFRetain, CFRelease, CFMakeCollectable.
