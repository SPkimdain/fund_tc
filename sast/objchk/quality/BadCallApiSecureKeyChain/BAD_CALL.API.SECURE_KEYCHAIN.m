#include <AppKit/AppKit.h>
#include <CoreFoundation/CoreFoundation.h>
#include <Security/Security.h>
#include <CoreServices/CoreServices.h>

#include <stdint.h>
void test() {
  unsigned int *ptr = 0;
  UInt32 length;
// 널을 해제하여함 - double free
  SecKeychainItemFreeContent(ptr, &length); // @violation : trying to free data which has not been allocated
}
void test2() { //@violation : data is not released
  unsigned int *ptr = 0;
  UInt32 *length = 0;
  void *outData;
//해제하지 않음
  OSStatus st =
    SecKeychainItemCopyContent(2, ptr, ptr, length, &outData); 
}
void test3() {
  unsigned int *ptr = 0;
  UInt32 *length = 0;
  void *outData;

  OSStatus st =
    SecKeychainItemCopyContent(2, ptr, ptr, length, &outData);
//if (outData != NULL) 가 필요

  SecKeychainItemFreeContent(ptr, outData);// @will-violation : only call free if a non-NULL buffer was returned
}
void test4() {
  unsigned int *ptr = 0;
  UInt32 *length = 0;
  void *outData;

  OSStatus st =
    SecKeychainItemCopyContent(2, ptr, ptr, length, &outData);
//새로 할당하기전 기존 해제 필요
  st = SecKeychainItemCopyContent(2, ptr, ptr, length, &outData);// @violation : release data before another call to the allocator

    SecKeychainItemFreeContent(ptr, outData); 
void test5() {
  SecKeychainItemRef itemRef = 0;
  SecKeychainAttributeInfo *info = 0;
  SecItemClass *itemClass = 0;
  SecKeychainAttributeList *attrList = 0;
  UInt32 *length = 0;
  void *outData = 0;

  OSStatus st =
    SecKeychainItemCopyAttributesAndData(itemRef, info,
                                         itemClass, &attrList,
                                         length, &outData);
// 할당자와 해제자 불일치
  SecKeychainItemFreeContent(attrList, outData); // @violation : deallocator doesn't match the allocator
}
//SecKeychainItemCopyContent
//SecKeychainFindGenericPassword
//SecKeychainFindInternetPassword
//SecKeychainItemFreeContent
//SecKeychainItemCopyAttributesAndData
//SecKeychainItemFreeAttributesAndData
