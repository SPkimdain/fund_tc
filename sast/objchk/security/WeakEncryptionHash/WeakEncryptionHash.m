#include <CommonCrypto/CommonDigest.h>
#import <Foundation/Foundation.h>

@interface WeakEncryptionHash : NSObject
-(void) test;
@end

@implementation WeakEncryptionHash
-(void) test {
    NSData *data = [NSData dataWithContentsOfFile:file];
    CC_MD5(data, [data length], result); // @violation
}
@end
