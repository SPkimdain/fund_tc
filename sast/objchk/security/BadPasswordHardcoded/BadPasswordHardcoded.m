#include <windows.h>
#include <sqlext.h>
#include <Foundation/Foundation.h>

@interface BadPasswordHardcoded : NSObject
-(void) test1;
-(void) test2;
-(void) test3:(Boolean)condition;
@end

@implementation BadPasswordHardcoded
-(void) test1 {
    NSString * password = @"hardcoded";
    SQLRETURN rc = SQLConnect(*hdbc, server, SQL_NTS, "user", SQL_NTS, password, SQL_NTS); // @violation
}

-(void) test2 {
    NSString * hardcoded = @"hardcoded";
    NSString * password = hardcoded;
    SQLRETURN rc = SQLConnect(*hdbc, server, SQL_NTS, "user", SQL_NTS, password, SQL_NTS); // @violation
}

-(void) test3:(Boolean)condition {
    NSString * password;
    if(condition) {
        password = @"hardcoded";
    } else {
        password = getPasswd();
    }
    SQLRETURN rc = SQLConnect(*hdbc, server, SQL_NTS, "user", SQL_NTS, password, SQL_NTS); // @violation
}
@end

// Get some password
NSString * getPasswd();
