#import <Foundation/Foundation.h>

@interface DIVbyZero : NSObject
-(void) allowed:(NSString *)argument;
-(void) forbidden:(NSString *)argument;
@end

void test2( int zero )
{
    double test = 505 / zero;
    double test2 = 505 / (zero-2);
    return;
}

void conditional(NSString * argument) {
    // Do something ...
    int one = 1;
    NSNumber * sum = [NSNumber numberWithInt:(1-one)];
    
    if ([sum isEqual:@(0)])
    {//check if branch for message expression
        double temp =  100 / ([sum intValue] +1);
        temp =  101 / [sum intValue]; //@violation
        test2(2); //@violation
        test2(0); //@violation
    }
    else
    {
        double temp =  200 / [sum intValue]; // sum is not zero -> safe
    }
}

@implementation DIVbyZero
-(void) allowed:(NSString *)argument {
    int zero = 0;
    
    double div = 102/(zero +1);
}

-(void) forbidden:(NSString *)argument {
    double div = 103/0; //@violation
    int one =1;
    double div2 = 104/(one -1); //@violation
    NSNumber * zeroNS = [NSNumber numberWithInt:(one -1)];
    double div3 = 105/[zeroNS intValue]; //@violation
}
@end
