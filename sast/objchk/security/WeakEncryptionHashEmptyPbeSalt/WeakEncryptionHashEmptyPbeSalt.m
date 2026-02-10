#import <CommonCrypto/CommonCrypto.h>

void HKDF_SHA256_Empty(NSData *seed, NSData *info, NSData *salt, int outputSize) {
    char prk[kCCHmacAlgSHA256] = {0};

    CCHmac(CC_SHA256_DIGEST_LENGTH, @"", 0, [seed bytes], [seed length], prk); //@violation

}

void HKDF_SHA256_Empty_Safe(NSData *seed, NSData *info, NSData *salt, int outputSize) {
    char prk[kCCHmacAlgSHA256] = {0};
    CCHmac(CC_SHA256_DIGEST_LENGTH, [salt bytes], [salt length], [seed bytes], [seed length], prk);
}
