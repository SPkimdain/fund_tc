#import <Foundation/Foundation.h>

@interface UNINITIALIZED_ASSIGN : NSObject
-(void) allowed:(NSString *)argument;
-(void) forbidden:(NSString *)argument;
@end

void allowed(NSString * argument) {
    // Do something ...
    
}

void forbidden(NSString * argument) {
    // Do something ...
    int * tempP;
    int *pointer = (int)tempP; // @violation
    NSString * tempstr;
    NSString * anotherStr =  tempstr;  //@violation
    
    
}

@implementation UNINITIALIZED_ASSIGN
-(void) allowed:(NSString *)argument {
    // Do something ...
    int a=0;
    int b=a;
}

-(void) forbidden:(NSString *)argument {
    // Do something ...
    int a;
    int b=a; //@violation    
    int c;
    c=a; //@violation    
}

@end
