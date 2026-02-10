#import <Foundation/Foundation.h>

@interface ClassTest : NSObject
- (void) callFunction;
@end


@implementation ClassTest
- (void) callFunction {
    NSLog(@"test.");
}
@end

char* useAfterFreeTest (int fd) {
    char *buf = (char*) malloc (BLOCK_SIZE);

    *buf = 10;

    if (!buf) { return NULL; }

    free(buf);
    *buf = 0; //@violation

    return 0;
}
