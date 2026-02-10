#import <Foundation/Foundation.h>

@interface IntegerOverflowTest : NSObject
-(int) integerOverflowFunction;
-(int) integerOverflowSafeFunction;
@end


@implementation IntegerOverflowTest
-(int) integerOverflowFunction {
    NSString* source = getenv("source");
    int value = [source intValue];

    int ret = 10 * value;  //@violation

	return ret;
}

-(int) integerOverflowFunction {
    NSString* source = getenv("source");
    int value = [source intValue];

    if(value > 100000) {
        return 0;
    }

    int ret = 55 * value;

	return ret;
}

@end
