#include <CommonCrypto/CommonCryptor.h>
#import <Foundation/Foundation.h>

@interface WeakEncryptionInsufficientKeySize : NSObject;
-(void) test1:(NSData *)text;
-(void) test2:(NSData *)text;
-(void) test3:(Boolean)cond withTest:(NSData *)text;
-(id) getSymmetricKeyBytes;
@end

@implementation WeakEncryptionInsufficientKeySize
-(void) test1:(NSData *)text {
    CCOperation op;
    CCOptions options;
    const void * iv;
    size_t textBufferSize;
    const void * dataIn;
    size_t dataInSize;
    size_t dataOutMoved;
    // Do something
    int keySize = 64;
    CCCryptorStatus ccStatus = CCCrypt(op, kCCAlgorithmDES, options, // @violation
                                      (const void *)[self getSymmetricKeyBytes],
                                       keySize, iv, (const void *) [text bytes], textBufferSize,
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
    // Do something
    int keySize = 64;
    keySize *= 2; // Safe since the key size will be 64 * 2 = 128
    CCCryptorStatus ccStatus = CCCrypt(op, kCCAlgorithmDES, options,
                                      (const void *)[self getSymmetricKeyBytes],
                                       keySize, iv, (const void *) [text bytes], textBufferSize,
                                      (void *)dataIn, dataInSize, &dataOutMoved);
}

-(void) test3:(Boolean)cond withTest:(NSData *)text {
    CCOperation op;
    CCOptions options;
    const void * iv;
    size_t textBufferSize;
    const void * dataIn;
    size_t dataInSize;
    size_t dataOutMoved;
    // Do something
    int keySize;
    if(cond) {
        keySize = 64;
    } else {
        keySize = 128;
    }
    CCCryptorStatus ccStatus = CCCrypt(op, kCCAlgorithmDES, options, // @violation
                                      (const void *)[self getKeyBytes],
                                       keySize, iv, (const void *) [text bytes], textBufferSize,
                                      (void *)dataIn, dataInSize, &dataOutMoved);
}
@end
