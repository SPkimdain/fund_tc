#include <Foundation/Foundation.h>
@interface MyObj2 : NSObject
    - (id)init;
@end

@implementation MyObj2
-(id) init
{
    return ^id(CGFloat multiplier) {
        NSAssert(!self.hasBeenInstalled,
                 @"Cannot modify constraint multiplier after it has been installed");

        self.layoutMultiplier = multiplier;
        return self; //@violation
    };
}

@end

