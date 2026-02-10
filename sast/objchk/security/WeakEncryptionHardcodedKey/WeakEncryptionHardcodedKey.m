#include <CommonCrypto/CommonCryptor.h>
#import <Foundation/Foundation.h>

@interface WeakEncryptionHardcodedKey : NSObject
-(void) test1:(NSData *)text;
-(void) test2:(NSData *)text;
-(void) test3:(Boolean)cond with:(NSData *)text;
-(id) getSymmetricKeyBytes;
@end

@implementation WeakEncryptionHardcodedKey
-(void) test1:(NSData *)text {
    CCOperation op;
    CCOptions options;
    const void * iv;
    size_t textBufferSize;
    const void * dataIn;
    size_t dataInSize;
    size_t dataOutMoved;
    // Do something ...
    NSString * key = @"hardcoded-key";
    CCCryptorStatus ccStatus = CCCrypt(op, kCCAlgorithmDES, options, // @violation
                                      (const void *)key,
                                       64, iv, (const void *) [text bytes], textBufferSize,
                                      (void *)dataIn, dataInSize, &dataOutMoved);
}

-(void) test2:(NSData *)text {
    CCOperation op;
    CCOptions options;
    const void * iv;
    size_t textBufferSize;
    const void * dataIn;
    size_t dataInSize;
    size_t dataOutMoved;
    // Do something ...
    CCCryptorStatus ccStatus = CCCrypt(op, kCCAlgorithmDES, options,
                                      (const void *)[self getSymmetricKeyBytes],
                                       64, iv, (const void *) [text bytes], textBufferSize,
                                      (void *)dataIn, dataInSize, &dataOutMoved);
    // Do another thing ...
    const void * key = (const void *)[self getSymmetricKeyBytes];
    ccStatus = CCCrypt(op, kCCAlgorithmDES, options,
                       key,
                       64, iv, (const void *) [text bytes], textBufferSize,
                       (void *)dataIn, dataInSize, &dataOutMoved);
}

-(void) test3:(Boolean)cond with:(NSData *)text{
    CCOperation op;
    CCOptions options;
    const void * iv;
    size_t keySize;
    size_t textBufferSize;
    const void * dataIn;
    size_t dataInSize;
    size_t dataOutMoved;
    // Do something ...
    NSString * key;
    if(cond) {
        key = @"hardcoded_key";
    } else {
        key = getKey();
    }
    CCCryptorStatus ccStatus = CCCrypt(op, kCCAlgorithmDES, options, // @violation
                                      (const void *)key,
                                      keySize, iv, (const void *) [text bytes], textBufferSize,
                                      (void *)dataIn, dataInSize, &dataOutMoved);
}
@end

NSString * getKey();
