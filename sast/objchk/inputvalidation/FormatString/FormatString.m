#import <Foundation/Foundation.h>

@interface FormatString : NSObject
-(void) test1;
@end

@implementation FormatString
-(void) test1 {
    char * untrusted = getenv("UNTRUSTED");
    char buf[100];
    char dest[100];
    strcpy(dest, untrusted); // Propagation
    sprintf(buf, dest, untrusted); // @violation
}
@end

void func() {
    char * untrusted = getenv("UNTRUSTED");
    char * untrustedSecondary = untrusted;
    char buf[100];
    sprintf(buf, getenv("UNTRUSTED"), untrusted); // @violation
    printf(untrustedSecondary, untrusted); // @violation
}

void dest(char * data) {
    char buf[100];
    sprintf(buf, "%s", data);
}

void src() {
    char * untrusted = getenv("UNTRUSTED");
    dest(untrusted);
}

char * getUntrusted(int a) {
    char * untrusted = NULL;
    if(a > 0) {
        untrusted = getenv("UNTRUSTED");
    }
    return untrusted;
}

char * getSimpleUntrusted() {
    return getenv("UNTRUSTED");
}

int dummy(char *);

int main(int argc, char * argv[]) {
    char buf[1024];
    sprintf(buf, argv[0], argv[1]); // @violation
    [NSString stringWithFormat:[NSString stringWithUTF8String: argv[1]], argv[2]]; // @violation
    [NSString stringWithFormat:[NSString stringWithUTF8String: argv[1]], argv[2]]; // @violation
    NSString * nsStr = [NSString stringWithUTF8String: argv[0]]; // Propagation
    [NSString stringWithFormat:nsStr]; // @violation
    sprintf(buf, getUntrusted(1), "hello"); // @violation
    char * untrusted = [nsStr UTF8String]; // Propagation
    NSLog([NSString stringWithUTF8String: untrusted], "data"); // @violation
}
