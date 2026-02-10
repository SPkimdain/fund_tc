#import <Foundation/Foundation.h>

@interface PathManipulation : NSObject
+(char *) mGetSource;
+(char *) mGetSource2Step:(int)a;
@end

@implementation PathManipulation
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
    NSFileManager * fm = [NSFileManager defaultManager];
    NSData * data;
    data = [fm contentsAtPath: [NSString stringWithUTF8String: [PathManipulation mGetSource]]]; // @violation
    data = [fm contentsAtPath: [NSString stringWithUTF8String: [PathManipulation mGetSource2Step: 2]]]; // @violation
}

int main(int argc, char * argv[]) {
    NSFileManager * fm = [NSFileManager defaultManager];
    NSData * data;
    data = [fm contentsAtPath: [NSString stringWithUTF8String: argv[1]]]; // @violation
    data = [fm contentsAtPath: [NSString stringWithUTF8String: getenv("SOURCE")]]; // @violation
    data = [fm contentsAtPath: [NSString stringWithUTF8String: getSource()]]; // @violation
    data = [fm contentsAtPath: [NSString stringWithUTF8String: getSource2Step()]]; // @violation
    data = [fm contentsAtPath: propagates()]; // @violation
    data = [fm contentsAtPath: @"SafePath"];
}
