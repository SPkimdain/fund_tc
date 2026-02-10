
#import <Foundation/Foundation.h>

int callFunction(char* buf, char* src) {
    strcpy(buf, src); //@violation
    return 0;
}
