#include <CoreFoundation/CoreFoundation.h>
void test() {
  int x[] = { 1 };
  int* y[] = { 1 };
  int* k ;
  CFArrayRef C = CFArrayCreate(0, (const void **)k, 1, &kCFTypeArrayCallBacks); //@violation
  CFArrayRef B = CFArrayCreate(0, (const void **)y, 1, &kCFTypeArrayCallBacks);
  CFArrayRef A = CFArrayCreate(0, (const void **)x, 1, &kCFTypeArrayCallBacks); //@violation

  // CFArray, CFDictionary, CFSet are created with non-pointer-size values.
}