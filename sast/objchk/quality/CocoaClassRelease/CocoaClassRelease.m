#include <Foundation/Foundation.h>
@interface MyClass : NSObject
@end

void test(void) {
  MyClass *mycar = [[MyClass alloc] init];
  [mycar release];
  [MyClass release]; // @violation
}

//Check for sending retain, release, or autorelease directly to a class.