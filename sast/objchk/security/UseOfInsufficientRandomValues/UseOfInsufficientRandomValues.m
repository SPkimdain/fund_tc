#include <stdlib.h>
#import <Foundation/Foundation.h>

@interface RandomTestClass
+(void) randomTestFunction;
@end

@implementation RandomTestClass
+(void) randomTestFunction {
    int cstyleRand = rand() % 255; //@violation

    int posixRand = random() % 255; //@violation

    int arcRand = arc4random() % 255;

    NSUInteger r = arc4random_uniform(255);
}
@end
