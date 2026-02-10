#import <Foundation/Foundation.h>

@interface LogForging : NSObject
+(char *) mGetSource;
+(char *) mGetSource2Step:(int)a;
@end

@implementation LogForging
+(char *) mGetSource {
    return getenv("SOURCE");
}
+(char *) mGetSource2Step:(int)a {
    if(a > 0) {
        return getenv("SOURCE");
    } else {
        return NULL;
    }
}
@end

char * getSource() {
    return getenv("SOURCE");
}

char * getSource2Step() {
    return getSource();
}

NSString * propagates() {
    return [NSString stringWithUTF8String: getSource()];
}

void func() {
    NSLog(@"%s", [LogForging mGetSource]); // @violation
    NSLog(@"%s", [LogForging mGetSource2Step: 2]); // @violation
}

int main(int argc, char * argv[]) {
    NSLog(@"%s", argv[1]); // @violation
    NSLog(@"%s", getenv("SOURCE")); // @violation
    NSLog(@"%s", getSource()); // @violation
    NSLog(@"%s", getSource2Step()); // @violation
    NSLog(@"%s", propagates()); // @violation
    NSLog(@"%s", "Safe");
    NSLog(@"%s", "Safe", getSource()); // @violation
    NSLog([NSString stringWithUTF8String: getSource()], "Safe");//@violation
}
