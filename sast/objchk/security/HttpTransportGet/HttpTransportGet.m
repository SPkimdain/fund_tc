#import <Foundation/Foundation.h>

@interface HttpTransportGet : NSObject
-(void) test1;
-(void) test2;
-(void) test3;
-(void) test4;
@end

@implementation HttpTransportGet
-(void) test1 {
    NSString * const URL = @"http://192.168.111.222:8080/test";
    NSURL * url = [NSURL URLWithString:URL];
    NSURLRequest * request = [NSURLRequest requestWithURL:url]; // @violation
    [[NSURLConnection alloc] initWithRequest:request delegate:self];
}

-(void) test2 {
    NSString * const URL = @"http://192.168.111.222:8080/test";
    NSURL * url = [NSURL URLWithString:URL];
    NSURLRequest * request = [NSURLRequest requestWithURL:url cachePolicy: NSURLRequestReloadIgnoringCacheData timeoutInterval:10.0]; // @violation
    [[NSURLConnection alloc] initWithRequest:request delegate:self];
}

-(void) test3 {
    NSString * const URL = @"http://192.168.111.222:8080/test";
    NSURL * url = [NSURL URLWithString:URL];
    NSMutableURLRequest * request = [NSMutableURLRequest requestWithURL:url];
    [request setHTTPMethod:@"GET"]; // @violation
}

-(void) test4 {
    NSString * const URL = @"http://192.168.111.222:8080/test";
    NSURL * url = [NSURL URLWithString:URL];
    NSMutableURLRequest * request = [NSMutableURLRequest requestWithURL:url];
    [request setHTTPMethod:@"POST"]; // Safe
}
@end
