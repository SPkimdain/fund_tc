#include <Foundation/Foundation.h>
void test() {
  [NSSet setWithObjects:@"Foo", "Bar", nil];     // @violation
   //argument should be an ObjC pointer type, not 'char *'
  [NSSet setWithObjects:@1, 2,nil];     // @violation
  [NSSet setWithObjects:@1.4, 2.5,nil];     // @violation
}

//NSArray, NSSet and NSDictionary.?
