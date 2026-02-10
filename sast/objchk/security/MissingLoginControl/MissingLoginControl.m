#import <Foundation/Foundation.h>

void mlcTest() {
    login(); //@violation
}

void mlcSafeTest() {
    for(int i = 0; i< 10; i++) {
        login();
    }
}

void loginAuthenticationTest() {
    //not controled loop.
    while(1) { //@violation
        //do something.
    }

    return;
}
