//
//  Created by PADEV2 on 2015. 11. 16..
//  Copyright © 2015년 PADEV2. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>


@interface RawStringtoURL : NSObject
-(void) test1:(NSData *)text;
-(void) test2:(NSData *)text;
-(void) test3:(NSData *)text;
@end

@implementation RawStringtoURL
-(void) test1:(NSData *)text {
    // Do something ...

    NSString *sampleUrl = getenv("srcs");
    NSString* encodedUrl = [sampleUrl stringByAddingPercentEncodingWithAllowedCharacters:[NSCharacterSet URLQueryAllowedCharacterSet]];
    BOOL isInstalled = [[[UIApplication sharedApplication] sharedApplication] openURL: [NSURL URLWithString:encodedUrl]];

    return;

}

-(void) test2:(NSData *)text {
    // Do something ...
    NSString *sampleUrl = getenv("srcs");
    NSString* encodedUrl = [sampleUrl stringByAddingPercentEscapesUsingEncoding:
                            NSUTF8StringEncoding];
    BOOL isInstalled = [[UIApplication sharedApplication] openURL: [NSURL URLWithString:sampleUrl]]; // @violation

    return;


}

-(void) test3:(NSData *)text {
    // Do something ...
    NSString *sampleUrl = getenv("srcs");
    NSString* encodedUrl = [sampleUrl stringByAddingPercentEscapesUsingEncoding:
                            NSUTF8StringEncoding];
    int temp = rand();
    if (temp)
    {
        
        BOOL isInstalled = [[UIApplication sharedApplication] openURL: encodedUrl];
    }
    else
    { // s = [s stringByAppendingString:@" - après"];
        //[UIApplication openURL: [sampleUrl stringByAppendingString:encodedUrl]];
        BOOL isInstalled_sec = [[UIApplication sharedApplication] openURL: [sampleUrl stringByAppendingString:encodedUrl]]; // @violation
        BOOL isInstalled = [[UIApplication sharedApplication] openURL: [encodedUrl stringByAppendingString:sampleUrl]]; // @violation
        
    }
    return;


}
@end
