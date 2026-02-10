#include <windows.h>
#include <sqlext.h>
#import <Foundation/Foundation.h>

@interface BadPasswordEmpty : NSObject
-(void) test1;
-(void) test2;
-(void) test3:(Boolean)condition;
@end

@implementation BadPasswordEmpty
-(void) test1 {
    NSString * password = @"";
    SQLRETURN rc = SQLConnect(*hdbc, server, SQL_NTS, "user", SQL_NTS, password, SQL_NTS); // @violation
}

-(void) test2 {
    NSString * emptyString = @"";
    NSString * password2 = emptyString;
    SQLRETURN rc = SQLConnect(*hdbc, server, SQL_NTS, "user", SQL_NTS, password2, SQL_NTS); // @violation
}

-(void) test3:(Boolean)condition {
    NSString * password3;
    if(condition) {
        password3 = @"password";
    } else {
        password3 = @"";
    }
    SQLRETURN rc = SQLConnect(*hdbc, server, SQL_NTS, "user", SQL_NTS, password3, SQL_NTS); // @violation
}

@end
