#import <Foundation/Foundation.h>

@interface CookieDomainTest : NSObject
- (void) cookieDomainTestFunction;
@end

@implementation CookieDomainTest
- (void) cookieDomainTestFunction {
    /* ... */

    NSDictionary *properties = [NSDictionary dictionaryWithObjectsAndKeys:
                                @".domain.com", NSHTTPCookieDomain,
                                @"/service", NSHTTPCookiePath,
                                @"testCookies", NSHTTPCookieName,
                                @"1", NSHTTPCookieValue,
                                nil];
    NSHTTPCookie *cookie = [NSHTTPCookie cookieWithProperties:properties];  //@violation

    NSArray* cookies = [NSArray arrayWithObjects: cookie, nil];

    NSDictionary * headers = [NSHTTPCookie requestHeaderFieldsWithCookies:cookies];

    [request setAllHTTPHeaderFields:headers];
}
@end
