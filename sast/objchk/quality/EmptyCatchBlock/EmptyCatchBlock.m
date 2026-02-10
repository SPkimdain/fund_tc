// main.m
#import <Foundation/Foundation.h>

int main(int argc, const char * argv[]) {
    @autoreleasepool {
        NSArray *inventory = @[@"Honda Civic",
                               @"Nissan Versa",
                               @"Ford F-150"];
        int selectedIndex = 3;
        @try {
            NSString *car = inventory[selectedIndex];
            NSLog(@"The selected car is: %@", car);
        } @catch(NSException *theException) { //@violation
            //do nothing in catch block
            //NSLog(@"An exception occurred: %@", theException.name);
            //NSLog(@"Here are some details: %@", theException.reason);
        } @finally {
            NSLog(@"Executing finally block");
        }
    }
    return 0;
}


int sub(int argc, const char * argv[]) {

    @autoreleasepool {
        NSArray *inventory = @[@"Honda Civic",
                               @"Nissan Versa",
                               @"Ford F-150"];
        int selectedIndex = 3;
        @try {
            NSString *car = inventory[selectedIndex];
            NSLog(@"The selected car is: %@", car);
        } @catch(NSException *theException) {
            //do nothing in catch block
            NSLog(@"An exception occurred: %@", theException.name);
            NSLog(@"Here are some details: %@", theException.reason);
        } @finally {
            NSLog(@"Executing finally block");
        }
    }
    return 0;
}


