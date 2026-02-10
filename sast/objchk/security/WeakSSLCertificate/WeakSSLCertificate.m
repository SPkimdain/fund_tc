#import <Foundation/Foundation.h>

@interface NSURLRequest (IgnoreSSL)
+(BOOL) allowsAnyHTTPSCertificationForHost:(NSString *)host;
@end

@implementation NSURLRequest (IgnoreSSL)
+(BOOL) allowsAnyHTTPSCertificateForHost:(NSString *)host {
    BOOL cond, subcond;
    BOOL ret;
    // Do something

    if(cond) {
        ret = YES;
    } else {
        ret = NO;
    }
    if(subcond) {
        return YES; // @violation
    } else {
        return ret; // @violation
    }
}
@end
