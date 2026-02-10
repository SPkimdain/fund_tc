#include <Foundation/Foundation.h>
@interface A : NSObject
- (void)foo:(NSError **)error;	// @violation
   //method accepting NSError** should have a non-void
@end

@implementation A
- (void)foo:(NSError **)error { // @violation 
  //method accepting NSError** should have a non-void
  // return value
}
@end
@interface B : NSObject
- (BOOL)foo:(NSError **)error;
@end

@implementation B
- (BOOL)foo:(NSError **)error {
  *error = 0; // potential null dereference
  return 0;
}
@end