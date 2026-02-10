#import <Foundation/Foundation.h>

@interface RelianceTest : NSObject<NSStreamDelegate>
+ (void) relianceOnUntrustedEnvInputsTest;
+ (void) relianceOnUntrustedEnvInputsSafeTest
@public
    CFReadStreamRef readStream;
    CFWriteStreamRef writeStream;
@end

@implementation RelianceTest
+ (void) relianceOnUntrustedEnvInputsTest {
    NSString* auth = getenv("user_info");
    UIWebView *webView = [[UIWebView alloc] initWithFrame:self.view.frame];
    NSURL *url = [NSURL URLWithString:@"https://www.web.net"];

    NSMutableURLRequest *mutableRequest =
        [NSMutableURLRequest requestWithURL:url];

    NSLog(@"%@", @"PersisteWebCookie");
    NSMutableString *cookieStringToSet = [[NSMutableString alloc] init];

    if (cookieStringToSet.length) {
        [mutableRequest setValue:auth forHTTPHeaderField:@"Cookie"]; //@violation

        NSLog(@"Cookie : %@", cookieStringToSet);
    }
    NSLog(@"%@", @"PersisteWebCookie Restored");

    [webView loadRequest:mutableRequest];

    [webView setBackgroundColor:[UIColor clearColor]];
    [self.view addSubview:webView];

}


+ (void) relianceOnUntrustedEnvInputsSafeTest {
    NSString* auth = getenv("user_info");
    NSURLSessionConfiguration * defaultConfigObject = [NSURLSessionConfiguration defaultSessionConfiguration];
    defaultConfigObject.requestCachePolicy = NSURLRequestReloadIgnoringLocalCacheData;
    NSURLSession * defaultSession = [NSURLSession sessionWithConfiguration:defaultConfigObject delegate:self delegateQueue:[NSOperationQueue mainQueue]];

    NSString * scriptURL = [NSString stringWithFormat:@"https://www.web.net"];

    NSMutableURLRequest * urlRequest = [NSMutableURLRequest requestWithURL:[NSURL URLWithString:scriptURL]];
    [urlRequest setHTTPMethod:@"POST"];
    [urlRequest setHTTPBody:[auth dataUsingEncoding:NSUTF8StringEncoding]];

    NSURLSessionDataTask * dataTask = [defaultSession dataTaskWithRequest:urlRequest];
    [dataTask resume];
}

@end
