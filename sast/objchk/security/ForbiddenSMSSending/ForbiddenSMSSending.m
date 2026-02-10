#include <Foundation/Foundation.h>
#include <UIKit/UIApplication.h>

@interface ForbiddenSMSSending : NSObject
-(void) test1;
-(void) test2;
-(void) test3;
-(void) test4;
-(void) test5;
@end

@implementation ForbiddenSMSSending
-(void) test1 {
    // Do something ...
    UIApplication * application = [UIApplication sharedApplication];
    [application openURL: @"sms:+821012345678"]; // @violation
}

-(void) test2 {
    // Do something ...
    UIApplication application = [UIApplication sharedApplication];
    NSString * url = "sms:+821012345678";
    [application openURL:url]; // @violation
}

-(void) test3 {
    // Do something ...
    UIApplication application = [UIApplication sharedApplication];
    NSString * url = "http://www.google.com"; // Safe URL: Not an SMS URL
    [application openURL:url];
}

-(void) test4 {
    // Do something ...
    CTMessageCenter * messageCenter = [CTMessageCenter sharedMessageCenter];
    [messageCenter sendSMSWithText:msgField.text serviceCenter:nil toAddress:@"+821012345678"]; // @violation
}

-(void) test5 {
    // Do something ...
    CTMessageCenter * messageCenter = [CTMessageCenter sharedMessageCenter];
    [messageCenter sendSMSWithText:msgField.text serviceCenter:nil toAddress:@"+821012345678" withMoreToFollow:YES]; // @violation
}
@end
