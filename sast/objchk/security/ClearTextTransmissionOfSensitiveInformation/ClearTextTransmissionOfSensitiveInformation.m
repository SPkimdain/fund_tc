#import <Foundation/Foundation.h>
#import <CommonCrypto/CommonCryptor.h>

@interface ClearTextClass : NSObject
- (void) clearTextFunction:(CFSocketRef) socket;
- (void) clearTextFunctionSafe:(CFSocketRef) socket;
@end

@implementation ClearTextClass
- (void) clearTextFunction:(CFSocketRef) socket {
    CFSocketError error = 0;

    NSString* pwd = getPassword();

    NSData* msgData = [pwd dataUsingEncoding:NSUTF8StringEncoding];

    error = CFSocketSendData (socket, NULL, (CFDataRef) msgData, 10); //@violation
}

- (void) clearTextFunctionSafe:(CFSocketRef) socket {
    NSString *const IV = @"AEE0515D0B08A4E4";
    NSString *const KEY =  @"9336565521E5F082BB5929E8E033BC69";
    NSData *key =[KEY dataUsingEncoding:NSUTF8StringEncoding];
    NSData *iv = [IV dataUsingEncoding:NSUTF8StringEncoding];

    CFSocketError error = 0;

    NSString* pwd = getPassword();

    NSData* msgData = [message dataUsingEncoding:NSUTF8StringEncoding];

    size_t cryptBytes = 0;
    NSMutableData *dataOut = [NSMutableData dataWithLength:dataIn.length + kCCBlockSizeBlowfish];

    CCOperation cc = getCCOperation();
    CCCryptorStatus ccStatus = CCCrypt( kCCEncrypt_or_kCCDecrypt,
        kCCAlgorithmAES, kCCOptionPKCS7Padding,
        key.bytes, key.length, iv.bytes,
        msgData.bytes, msgData.length, dataOut.mutableBytes, dataOut.length, &cryptBytes);


    error = CFSocketSendData (socket, NULL, (CFDataRef) dataOut, 10);
}

@end