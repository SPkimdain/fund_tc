//
//  FMLicenseXMLChecker.m
//  FSMTestForIPhone
//
//  Created by 최영근 on 10. 7. 16..
//  Copyright 2010 (주)파수닷컴. All rights reserved.
//

#import "FMLicenseXMLChecker.h"


@implementation FMLicenseXMLChecker

@synthesize isInStatus;
@synthesize isInCode;
@synthesize isInMessage;
@synthesize isUniqueId;
@synthesize isInExtData;
@synthesize isInLicSvrCertSubjectId;
@synthesize isInDevCertSubjectId;

- (void)didEnable:(BOOL)isEnable forElement:(NSString *)startTag
{
	if ([startTag isEqualToString:STATUS]) {
		isInStatus = isEnable;
	}
	else if (isInStatus && [startTag isEqualToString:CODE]) {
		isInCode = isEnable;
	}
	else if (isInStatus && [startTag isEqualToString:MESSAGE]) {
		isInMessage = isEnable;
	}
    //unique_id 는 status밖에 있다. 코드 수정(v1.2)
    //    else if (isInStatus && [startTag isEqualToString:UNIQUEID_ID]) {
    //		isUniqueId = isEnable;
    //	}
    else if ([startTag isEqualToString:UNIQUEID_ID]) {
		isUniqueId = isEnable;
	}
	else if ([startTag isEqualToString:CRYPTOINFO]) {
		isInCryptoInfoHeader = isEnable;
	}
	else if (isInCryptoInfoHeader && [startTag isEqualToString:SUBJECT_ID]) {
		isInDevCertSubjectId = isEnable;
	}
	else if ([startTag isEqualToString:ENCCEK]) {
		isInEncryptedCek = isEnable;
	} else if ([startTag isEqualToString:CONTENTS]) {
		isInContents = isEnable;
	} else if (isInContents && [startTag isEqualToString:CONTENTS_ID]) {
		isInContentsId = isEnable;
	} else if (isInContents && [startTag isEqualToString:CONTENTS_DIGEST]) {
		isInContentsDiest = isEnable;
	} else if (isInContents && isInContentsDiest && [startTag isEqualToString:CONTENTS_DIGEST_ALG]) {
		isInContentsDiestAlg = isEnable;
	} else if (isInContents && isInContentsDiest && [startTag isEqualToString:CONTENTS_DIGEST_VAL]) {
		isInContentsDiestVal = isEnable;
	} else if ([startTag isEqualToString:VIEW]) {
		isInView = isEnable;
	} else if ([startTag isEqualToString:TIME]) {
		isInTime = isEnable;
	} else if ([startTag isEqualToString:FROM]) {
		isInTimeFrom = isEnable;
	} else if ([startTag isEqualToString:UNTIL]) {
		isInTimeUntil = isEnable;
	} else if ([startTag isEqualToString:ACCESS]) {
		isInAccess = isEnable;
	} else if ([startTag isEqualToString:COMMENT]) {
		isInComment = isEnable;
	}
	else if ([startTag isEqualToString:SIGNATURE]) {
		isInSignature = isEnable;
	}
	else if (isInSignature && [startTag isEqualToString:SUBJECT_ID]) {
		isInLicSvrCertSubjectId = isEnable;
	}
	else if (isInSignature && [startTag isEqualToString:SIGNATURE_DIGEST]) {
		isInSignatureDiest = isEnable;
	} else if (isInSignature && isInSignatureDiest && [startTag isEqualToString:SIGNATURE_DIGEST_ALG]) {
		isInSignatureDiestAlg = isEnable;
	} else if (isInSignature && [startTag isEqualToString:SIGNATURE_VAL]) {
		isInSignatureVal = isEnable;
	} else if ([startTag isEqualToString:EXTDATA]) {
		isInExtData = isEnable;
	} else {
		//Do Nothing
		;
	}
}

- (BOOL)isCryptoInfoHeader
{
	if (isInCryptoInfoHeader && (isInEncryptedCek==NO)) {
		return YES;
	}
	return NO;
}

- (BOOL)isEncryptedCek
{
	if (isInCryptoInfoHeader && isInEncryptedCek) {
		return YES;
	}
	return NO;
}

- (BOOL)isContentsId
{
	if (isInContents && isInContentsId) {
		return true;
	}
	return NO;
}

- (BOOL)isContentsDiestAlg
{
	if (isInContents && isInContentsDiest && isInContentsDiestAlg) {
		return YES;
	}
	return NO;
}

- (BOOL)isContentsDiestVal
{
	if (isInContents && isInContentsDiest && isInContentsDiestVal) {
		return YES;
	}
	return NO;
}

- (BOOL)isView
{
	if (isInView && (!isInTime)) {
		return YES;
	}
	return NO;
}

- (BOOL)isTimeFrom
{
	if (isInView && isInTime && isInTimeFrom) {
		return YES;
	}
	return NO;
}

- (BOOL)isTimeUntil
{
	if (isInView && isInTime && isInTimeUntil) {
		return YES;
	}
	return NO;
}
- (BOOL)isAccess
{
	if (isInView && isInAccess) {
		return YES;
	}
	return NO;
}

- (BOOL)isSignature
{
	if (isInSignature) {
		return YES;
	}
	return NO;
}

- (BOOL)isComment
{
	return (isInView && isInComment);
}

- (BOOL)isSignatureDiestAlg
{
	if (isInSignature && isInSignatureDiest && isInSignatureDiestAlg) {
		return YES;
	}
	return NO;
}

- (BOOL)isSignatureVal
{
	if (isInSignature && isInSignatureVal) {
		return YES;
	}
	return NO;
}

- (void)setAllFalse
{
	isInCryptoInfoHeader = isInEncryptedCek = isInContents = isInContentsId
	= isInContentsDiest = isInContentsDiestAlg = isInContentsDiestVal = isInView
	= isInTime = isInTimeFrom = isInTimeUntil = isInAccess = isInSignature
	= isInSignatureDiest = isInSignatureDiestAlg = isInSignatureVal = NO;
}

@end
