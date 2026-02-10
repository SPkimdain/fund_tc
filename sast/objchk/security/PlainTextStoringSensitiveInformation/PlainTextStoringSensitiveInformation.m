


#import <Foundation/Foundation.h>

@interface HttpTransport : NSObject
-(void) test1;
@end

@implementation HttpTransport
-(void) test1 {
    NSString * const key = @"password";
   NSUserDefaults *userDefaults = [NSUserDefaults standardUserDefaults];

   [userDefaults setObject:value forKey:key];//@violation
   // – setBool:forKey:
   // – setFloat:forKey:
   // in your case
   [userDefaults synchronize];

}


