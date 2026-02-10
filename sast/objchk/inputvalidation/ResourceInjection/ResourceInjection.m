#import <Foundation/Foundation.h>

@interface ResourceInjection : NSObject
+(char *) mGetSource;
+(char *) mGetSource2Step:(int)a;
@end

@implementation ResourceInjection
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
    CFReadStreamRef readStream;
    CFWriteStreamRef writeStream;
    CFStreamCreatePairWithSocketToHost(NULL, (CFStringRef)[ResourceInjection mGetSource], 80, &readStream, &writeStream); // @violation
    CFStreamCreatePairWithSocketToHost(NULL, (CFStringRef)[ResourceInjection mGetSource2Step: 2], 80, &readStream, &writeStream); // @violation
}

int main(int argc, char * argv[]) {
    CFReadStreamRef readStream;
    CFWriteStreamRef writeStream;
    CFStreamCreatePairWithSocketToHost(NULL, (CFStringRef)argv[1], 80, &readStream, &writeStream); // @violation
    CFStreamCreatePairWithSocketToHost(NULL, (CFStringRef)getenv("SOURCE"), 80, &readStream, &writeStream); // @violation
    CFStreamCreatePairWithSocketToHost(NULL, (CFStringRef)getSource(), 80, &readStream, &writeStream); // @violation
    CFStreamCreatePairWithSocketToHost(NULL, (CFStringRef)getSource2Step(), 80, &readStream, &writeStream); // @violation
    CFStreamCreatePairWithSocketToHost(NULL, (CFStringRef)propagates(), 80, &readStream, &writeStream); // @violation
    CFStreamCreatePairWithSocketToHost(NULL, (CFStringRef)"Safe", 80, &readStream, &writeStream);
}
