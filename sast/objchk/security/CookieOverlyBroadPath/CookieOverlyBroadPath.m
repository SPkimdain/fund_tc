#import <Foundation/Foundation.h>

@interface CookiePathTest : NSObject
- (void) cookieDomainTestFunction;
@end

@implementation CookiePathTest
- (void) cookieDomainTestFunction {
    /* ... */

    NSDictionary *properties = [NSDictionary dictionaryWithObjectsAndKeys:
                                @"www.domain.com", NSHTTPCookieDomain,
                                @"/", NSHTTPCookiePath,
                                @"testCookies", NSHTTPCookieName,
                                @"1", NSHTTPCookieValue,
                                nil];
    NSHTTPCookie *cookie = [NSHTTPCookie cookieWithProperties:properties]; //@violation

    NSArray* cookies = [NSArray arrayWithObjects: cookie, nil];

    NSDictionary * headers = [NSHTTPCookie requestHeaderFieldsWithCookies:cookies];

    [request setAllHTTPHeaderFields:headers];
}
@end
