#import <Foundation/Foundation.h>

void debugLog(NSString* str) {
    NSLog(@"%@", str); //@violation
}
