
#import <Foundation/Foundation.h>

@interface MissingAuthenticationTest : NSObject
-(void) maTest;
-(void) maSafeTest;
@end

@implementation MissingAuthenticationTest
- (void)maTest() {
    UITextField* userField = [[UITextField alloc] init];
    UITextField* pwdField = [[UITextField alloc] init];

    //do something

    NSString* user = [userField text];
    NSString* pwd = [pwdField text];

    modifyMember(user, pwd); //@violation
}

- (void)maSafeTest() {
    UITextField* userField = [[UITextField alloc] init];
    UITextField* pwdField = [[UITextField alloc] init];

    //do something

    NSString* user = [userField text];
    NSString* pwd = [pwdField text];

    validateUser(user);

    modifyMember(user, pwd);
}

}@end
