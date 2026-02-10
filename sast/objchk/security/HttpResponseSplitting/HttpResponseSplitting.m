#import <Foundation/Foundation.h>

@interface HttpResponseSplittingTest : NSObject
-(void) hrsTest1;
-(void) hrsTest2;
-(void) hrsSafeTest
@end

@implementation HttpResponseSplittingTest
-(void) hrsTest1 {
    NSString * const URL = @"http://192.168.111.222:8080/test";
    NSMutableURLRequest * request = [NSMutableURLRequest requestWithURL:[NSURL URLWithString:URL]];
    [[NSURLConnection alloc] initWithRequest:request delegate:self];

    //do post request for parameter passing
    [request setHTTPMethod:@"POST"];

    //set the content type to JSON
    [request setValue:@"xml" forHTTPHeaderField:@"Content-Type"];

    //passing key as a http header request
    [request addValue:@"value1" forHTTPHeaderField:@"key1"];

    NSString* str = getenv("source");

    //passing key as a http header request
    [request addValue:str forHTTPHeaderField:@"key2"]; //@violation
}

-(void) hrsTest2 {
    NSString * const URL = @"http://192.168.111.222:8080/test";
    NSURL * url = [NSURL URLWithString:URL];
    NSURLRequest * request = [NSURLRequest requestWithURL:url];
    [[NSURLConnection alloc] initWithRequest:request delegate:self];

    //do post request for parameter passing
    [request setHTTPMethod:@"POST"];

    //set the content type to JSON
    [request setValue:@"xml" forHTTPHeaderField:@"Content-Type"];

    //passing key as a http header request
    [request addValue:@"value1" forHTTPHeaderField:@"key1"];

    NSString* str = getenv("source");

    //passing key as a http header request
    [request addValue:str forHTTPHeaderField:@"key2"]; //@violation
}

-(void) hrsSafeTest {
    NSString * const URL = @"http://192.168.111.222:8080/test";
    NSMutableURLRequest * request = [NSMutableURLRequest requestWithURL:[NSURL URLWithString:URL]];
    [[NSURLConnection alloc] initWithRequest:request delegate:self];

    //do post request for parameter passing
    [request setHTTPMethod:@"POST"];

    //set the content type to JSON
    [request setValue:@"xml" forHTTPHeaderField:@"Content-Type"];

    //passing key as a http header request
    [request addValue:@"value1" forHTTPHeaderField:@"key1"];

    NSString* str = getenv("source");

    NSString* safe = [str stringByReplacingOccurrencesOfString: @"\n" withString: @""];

    //passing key as a http header request
    [request addValue:safe forHTTPHeaderField:@"key2"];
}

}
@end
