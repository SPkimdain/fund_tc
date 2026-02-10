#import <Foundation/Foundation.h>

@interface TemporaryFileWriting : NSObject
-(void) test1;
-(void) test2;
-(void) test3:(Boolean)condition;
-(void) test4;
@end

@implementation TemporaryFileWriting
-(void) test1 {
    NSString * contents = @"This is a contents";
    [contents writeToFile:@"/var/tmp/contents.txt" atomically: YES]; // @violation
}

-(void) test2 {
    NSString * contents = @"This is a contents";
    NSString * target = @"/var/tmp/contents.txt";
    [contents writeToFile:target atomically:NO encoding:NSStringEncodingConversionAllowLossy error:nil]; // @violation
}

-(void) test3:(Boolean)condition {
    NSString * contents = @"This is a contents";
    NSString * target;
    if(condition) {
        target = @"/var/tmp/contents.txt";
    } else {
        target = @"/var/contents/contents.txt";
    }
    [contents writeToFile:@"/var/tmp/contents.txt" atomically: YES]; // @violation
}

-(void) test4 {
    NSString * contents = @"This is a contents";
    NSString * target = @"/var/contents/contents.txt";
    [contents writeToFile:target atomically: YES];
}
@end
