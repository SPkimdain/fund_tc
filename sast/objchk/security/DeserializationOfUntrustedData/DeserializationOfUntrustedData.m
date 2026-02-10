#import <Foundation/Foundation.h>

@interface MyCoding : NSObject<NSCoding> //@violation
@property(nonatomic, strong) NSString *name;
@property(nonatomic, assign) NSInteger value;
@end
