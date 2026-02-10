#import <Foundation/Foundation.h>

@interface NULL_DEREFERENCE : NSObject
-(void) allowed:(NSString *)argument;
-(void) forbidden:(NSString *)argument;
@end


void allowed(NSString * argument) {
    // Do something ...
    int a = 10;
    int b = *(&a);
    
}

void forbidden(NSString * argument) {
    // Do something ...
    int a = NULL;
    int * pointA = &a;
    int b = *(pointA); //@violation
    b = *(&a); //@violation
    test(NULL);  
    test(3);
    test2(4);
    test2(NULL); //@violation
}


// C
void test(int *q) {
  if (q)
    return;

  int x = q[0]; //@violation
}
// C
void test2(int *p) {
  
    *p = 0; //violattion triggered by caller
}



// Objective-C
@interface MyClass {
@public
  int x;
}
@end

void test4() {
  MyClass *obj = 0;
  obj->x = 1; //@violation
}


@implementation NULL_DEREFERENCE
-(void) allowed:(NSString *)argument {
    // Do something ...
    
}

-(void) forbidden:(NSString *)argument {
    // Do something ...
    NSString * nullStr = NULL;
    //argument = [argument stringByAppendingString:nullStr]; 
}
@end
