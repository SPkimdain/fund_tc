
//  #compile passed
//  Created by PADEV2 on 2015. 11. 16..
//  Copyright © 2015년 PADEV2. All rights reserved.
//

#import <Foundation/Foundation.h>


@interface NullDereference : NSObject
-(void) test1:(NSData *)text;
-(void) test2:(NSData *)text;
-(void) test3:(NSData *)text;
@end


@implementation NullDereference
-(void) test1:(NSData *)text {

    void * tempVoidPointer = NULL;
    NSString * tempNSStringPointer = NULL;
    NSString * tempString = @"hello!";
    
    if(!tempVoidPointer)
    {
        NSString *appendedStr = [tempNSStringPointer stringByAppendingString:tempString]; //@violation
        appendedStr;
    }

    if(tempNSStringPointer == "Hello")
    {
        NSString *appendedStr = [tempNSStringPointer stringByAppendingString:tempString]; //safe
        appendedStr;
    }
}

-(void) test2:(NSData *)text {
    
    NSString * string1 = [[NSString alloc] initWithString:@"This is a test string."];
    NSMutableString * string2 = [string1 mutableCopy];
   
    
    
}
-(void) test3:(NSData *)text {

    
//    NSString *tempString = @"temp!";
    NSString *nullString = NULL;    
    NSArray *objCArray = [NSArray arrayWithObjects:@"1",nullString,tempString, @"2", nil];
    NSString *tempString = objCArray[1];
    
    
    tempString = [tempString stringByAppendingString:@"1"]; //@violation
    NSString * newstring = [tempString stringByAppendingString:@"1"]; //@violation 
    
    
    
    
    
}
@end

struct s
{
	int a;
};


void nullCall(struct s* ptr2)
{

    ptr2->a;
}

int main ()
{



    struct s *ptr;

    //(*ptr) = (void *)0;
    ptr = 0;

    nullCall(ptr); //@violation NULL_DEREF

    ptr->a = 5;  //@violation NULL_DEREF
    
     return 0;
}
