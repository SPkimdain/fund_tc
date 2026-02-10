//
//  xssTest.m
//  testacse
//
//  Created by PADEV2 on 2015. 12. 28..
//  Copyright © 2015년 PADEV2. All rights reserved.
//

#import <Foundation/Foundation.h>


@interface XSS : NSObject
-(void) connection:(NSURLConnection *)connection didReceiveAuthenticationChallenge:(NSURLAuthenticationChallenge *)challenge;
- (BOOL)httpPostWithUrl:(NSString *)url headersAndValues:(NSDictionary *)headersAndValues delegate:(id)delegate;
@end



@implementation XSS




- (void)connection:(NSURLConnection *)connection didReceiveAuthenticationChallenge:(NSURLAuthenticationChallenge *)challenge {
    
    if ([challenge.protectionSpace.authenticationMethod isEqualToString:NSURLAuthenticationMethodServerTrust]) {
        SecTrustResultType result;
        SecTrustEvaluate(challenge.protectionSpace.serverTrust, & result);
        
        if(result == kSecTrustResultProceed ||  result == kSecTrustResultUnspecified) {
            [challenge.sender useCredential:[NSURLCredential credentialForTrust: challenge.protectionSpace.serverTrust] forAuthenticationChallenge: challenge];
            return;
        }
    }
}




- (BOOL)httpPostWithUrl:(NSString *)url headersAndValues:(NSDictionary *)headersAndValues delegate:(id)delegate
{

    NSMutableString *bodyString = [[NSMutableString alloc] initWithString:@""];
    for (NSString *key in [headersAndValues allKeys])
    {
        [bodyString appendString:[NSString stringWithFormat:@"%@=%@&", key, headersAndValues[key]]];
    }
    
    NSMutableURLRequest *urlRequest = [NSMutableURLRequest requestWithURL:[NSURL URLWithString:url]
                                                              cachePolicy:NSURLRequestReloadIgnoringLocalCacheData
                                                          timeoutInterval:20.0f];
    [urlRequest setHTTPMethod:@"POST"];
    [urlRequest setValue:@"application/x-www-form-urlencoded" forHTTPHeaderField:@"content-type"];
    //if (bodyString.length)
    {
        //bodyString = [bodyString stringByDecodingHTMLEntities:bodyString]
        NSString *requestBody = [bodyString substringToIndex:bodyString.length-1];
        NSData *requestData = [requestBody dataUsingEncoding:NSUTF8StringEncoding allowLossyConversion:YES];
        [urlRequest setHTTPBody:requestData];
        
        
        NSURLConnection *connection =[[NSURLConnection alloc] initWithRequest:urlRequest delegate:self]; //@violation
        if (connection)
        {
            // do something...
        }
        return true;
    }
    return false;

}


@end

