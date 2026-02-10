#import <Foundation/Foundation.h>

@interface FLOAT_LOOP_COUNTER : NSObject
-(void) allowed:(NSString *)argument;
-(void) forbidden:(NSString *)argument;
@end


void allowed(NSString * argument) {
    // Do something ...
    
    int i = 10.0;
    
    for(i = 0; i< (int)11.5; i ++)
    {
    	
    }

    
   
    
}

void forbidden(NSString * argument) {
    // Do something ...
    
    float i = 10.0;
    
    for(i = 0; i< 11.5; i ++) //@violation
    {
    	
    }
    for (float x = 0.1f; x <= 1.0f; x += 0.1f) {} //@violation
    
}

@implementation FLOAT_LOOP_COUNTER
-(void) allowed:(NSString *)argument {
    // Do something ...
    
    
}

-(void) forbidden:(NSString *)argument {
    // Do something ...
    
    
}
@end
