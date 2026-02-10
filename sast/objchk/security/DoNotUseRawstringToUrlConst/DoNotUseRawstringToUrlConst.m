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
-(void) test2:(NSData *)text {
    // Do something ...
    NSString *sampleUrl = @"http://www.google.com/search.jsp?params=Java Developer";
    
    BOOL isInstalled = [[UIApplication sharedApplication] openURL: [NSURL URLWithString:sampleUrl]]; // @violation
    
    //-> url.evaluate() =>
       //UnknownValue([NSURL URLWithString:sampleUrl])
       //UnknownValue([NSURL URLWithString:ConstValue("@http://...")])
    
    return;


}

-(void) test3:(NSData *)text {
    // Do something ...
    NSString *sampleUrl = @"http://www.google.com/search.jsp?params=Java Developer";
    NSString* encodedUrl = [sampleUrl stringByAddingPercentEscapesUsingEncoding:
                            NSUTF8StringEncoding];
    int temp = rand();
    if (temp)
    {
        BOOL isInstalled = [[UIApplication sharedApplication] openURL: encodedUrl]; 
    }
    else
    { // s = [s stringByAppendingString:@" - après"];
        BOOL isInstalled = [[UIApplication sharedApplication] openURL: [sampleUrl stringByAppendingString:encodedUrl]]; // @violation
    }
    return;
    
    
}
@end