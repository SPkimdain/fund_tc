#import <Foundation/Foundation.h>

@interface BadCallObjCForbidden : NSObject
-(void) allowed:(NSString *)argument;
-(void) forbidden:(NSString *)argument;
-(void) test1;
-(void) test2:(MKOverlayView)view drawMapRect:(MKMapRect)mapRect;
@end

void allowed(NSString * argument) {
    // Do something ...
}

void forbidden(NSString * argument) {
    // Do something ...
}

@implementation BadCallObjCForbidden
-(void) allowed:(NSString *)argument {
    // Do something ...
}

-(void) forbidden:(NSString *)argument {
    // Do something ...
}

-(void) test1 {
    allowed(@"Argument");
    // ...
    char * routeChangeID=kAudioSessionProperty_AudioRouteChange;
    AudioSessionAddPropertyListener(routeChangeID,handleRouteChangeCallBack,(__bridge void *)(self)); // @violation
}

-(void) test2: (MKOverlayView)view drawMapRect: (MKMapRect)mapRect {
    [self allowed:@"Argument"];
    [view rectForMapRect:mapRect]; // @violation
}
@end
