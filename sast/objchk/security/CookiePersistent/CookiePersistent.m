#import <Foundation/Foundation.h>

@interface CookiePersistentTest : NSObject
- (void) cookiePersistentTestFunction;
@end

@implementation CookiePersistentTest
- (void) cookiePersistentTestFunction {
    /* ... */

    NSDictionary *properties = [NSDictionary dictionaryWithObjectsAndKeys:
                                @"www.domain.com", NSHTTPCookieDomain,
                                @"/service", NSHTTPCookiePath,
                                @"testCookies", NSHTTPCookieName,
                                @"1", NSHTTPCookieValue,
                                [[NSDate date] dateByAddingTimeInterval: 60 * 60 * 24 * 365 * 10], NSHTTPCookieExpires,
                                nil];
    NSHTTPCookie *cookie = [NSHTTPCookie cookieWithProperties:properties];  //@violation

    NSArray* cookies = [NSArray arrayWithObjects: cookie, nil];

    NSDictionary * headers = [NSHTTPCookie requestHeaderFieldsWithCookies:cookies];

    [request setAllHTTPHeaderFields:headers];
}
@end
