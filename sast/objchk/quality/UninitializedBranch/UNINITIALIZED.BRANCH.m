#import <Foundation/Foundation.h>

@interface UNINITIALIZED_BRANCH : NSObject
-(void) allowed:(NSString *)argument;
-(void) forbidden:(NSString *)argument;
@end

void allowed(NSString * argument) {
    // Do something ...
    
}

void forbidden(NSString * argument) {
    // Do something ...
    
}

@implementation UNINITIALIZED_BRANCH
-(void) allowed:(NSString *)argument {
    // Do something ...
    int b=0;
    
    if(b)
    {
        return;
    }
    else
    {
        return;
    }

}

-(void) forbidden:(NSString *)argument {
    // Do something ...
    int a;
    
    if(a) //@violation
    {
        return;
    }
    else
    {
        return;
    }
}
@end
