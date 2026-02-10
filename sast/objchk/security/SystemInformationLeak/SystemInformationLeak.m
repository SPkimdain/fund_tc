#import <Foundation/Foundation.h>

int systemInformationLeakTest () {
    int x = 0;
    @try {
        //do something.
    }
    @catch(NSException* ex) {
        NSLog(@"Exception %@, %@", [ex name], [ex reason]); //@violation

        NSLog(@"Exception catched.");
    }
    return 0;
}
