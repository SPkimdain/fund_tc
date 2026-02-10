
#import <Foundation/Foundation.h>

@interface WeakPasswordRequirementsTest : NSObject
-(void) wprTest;
-(void) wprSafeTest;
@end

@implementation WeakPasswordRequirementsTest
- (void)wprTest() {
    UITextField* userField = [[UITextField alloc] init];
    UITextField* pwdField = [[UITextField alloc] init];

    //do something

    NSString* user = [userField text];
    NSString* pwd = [pwdField text];

    createUser(user, pwd); //@violation
}

- (void)wprSafeTest() {
    UITextField* userField = [[UITextField alloc] init];
    UITextField* pwdField = [[UITextField alloc] init];

    //do something

    NSString* user = [userField text];
    NSString* pwd = [pwdField text];

    validatePassword(pwd);

    createUser(user, pwd);
}

}@end
