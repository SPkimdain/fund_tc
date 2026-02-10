#import <Foundation/Foundation.h>

@interface HttpTransport : NSObject
-(void) test1;
-(void) test2;
-(void) test3:(Boolean)condition;
-(void) test4:(NSMutableURLRequest *)request;
@end

@implementation HttpTransport
-(void) test1 {
    NSString * const URL = @"http://192.168.111.222:8080/test";
    NSMutableURLRequest * request = [NSMutableURLRequest requestWithURL:[NSURL URLWithString:URL]]; // @violation
    [[NSURLConnection alloc] initWithRequest:request delegate:self];
}

-(void) test2 {
    NSString * const URL = @"http://192.168.111.222:8080/test";
    NSURL * url = [NSURL URLWithString:URL];
    NSURLRequest * request = [NSURLRequest requestWithURL:url]; // @violation
    [[NSURLConnection alloc] initWithRequest:request delegate:self];
}

-(void) test3:(Boolean)condition {
    NSString * userURL;
    if(condition) {
        userURL = @"https://192.168.111.222:8080/test";
    } else {
        userURL = @"http://192.168.111.222:8080/test";
    }
    NSURL * url = [NSURL URLWithString:userURL];
    NSURLRequest * request = [NSURLRequest requestWithURL:url]; // @violation
    [[NSURLConnection alloc] initWithRequest:request delegate:self];
}

-(void) test4:(NSMutableURLRequest *)request {
    NSString * const URL = @"http://192.168.111.222:8080/test";
    NSURL * url = [NSURL URLWithString:URL];
    [request setURL:url]; // @violation
}
@end
