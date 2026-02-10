#include <CommonCrypto/CommonCryptor.h>
#import <Foundation/Foundation.h>

@interface WeakEncryptionRiskyAlgorithm : NSObject
-(void) test1:(NSData *)text;
-(void) test2:(NSData *)text;
-(void) test3:(Boolean)cond withText:(NSData *)text;
-(void) test4:(NSData *)text;
-(id) getSymmetricKeyBytes;
@end

@implementation WeakEncryptionRiskyAlgorithm
-(void) test1:(NSData *)text {
    CCOperation op;
    CCOptions options;
    const void * iv;
    size_t textBufferSize;
    const void * dataIn;
    size_t dataInSize;
    size_t dataOutMoved;
    // Do something ...
    CCCryptorStatus ccStatus = CCCrypt(op, kCCAlgorithmDES, options, // @violation
                                      (const void *)[self getSymmetricKeyBytes],
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
    CCAlgorithm algorithm = kCCAlgorithmDES;
    CCCryptorStatus ccStatus = CCCrypt(op, algorithm, options, // @violation
                                      (const void *)[self getSymmetricKeyBytes],
                                       64, iv, (const void *) [text bytes], textBufferSize,
                                      (void *)dataIn, dataInSize, &dataOutMoved);
}

-(void) test3:(Boolean)cond withText:(NSData *)text {
    CCOperation op;
    CCOptions options;
    const void * iv;
    size_t textBufferSize;
    const void * dataIn;
    size_t dataInSize;
    size_t dataOutMoved;
    // Do something ...
    CCAlgorithm algorithm;
    if(cond) {
        algorithm = kCCAlgorithmDES;
    } else {
        algorithm = kCCAlgorithmAES128;
    }
    CCCryptorStatus ccStatus = CCCrypt(op, algorithm, options, // @violation
                                      (const void *)[self getSymmetricKeyBytes],
                                       64, iv, (const void *) [text bytes], textBufferSize,
                                      (void *)dataIn, dataInSize, &dataOutMoved);
}

-(void) test4:(NSData *)text {
    CCOperation op;
    CCOptions options;
    const void * iv;
    size_t textBufferSize;
    const void * dataIn;
    size_t dataInSize;
    size_t dataOutMoved;
    // Do something ...
    CCCryptorStatus ccStatus = CCCrypt(op, kCCAlgorithmAES128, options,
                                      (const void *)[self getSymmetricKeyBytes],
                                       64, iv, (const void *) [text bytes], textBufferSize,
                                      (void *)dataIn, dataInSize, &dataOutMoved);
}
@end
