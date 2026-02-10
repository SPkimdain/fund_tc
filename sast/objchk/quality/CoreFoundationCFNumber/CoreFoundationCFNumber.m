#include <CoreFoundation/CoreFoundation.h>
CFNumberRef test(unsigned char x) {
  unsigned char y;
  return CFNumberCreate(0, kCFNumberSInt16Type, &y); //@violation
   // 8 bit integer is used to initialize a 16 bit integer
  //Check for improper uses of CFNumberCreate.
}