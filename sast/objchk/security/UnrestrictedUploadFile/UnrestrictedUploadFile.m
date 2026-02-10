#include <CommonCrypto/CommonDigest.h>
#import <Foundation/Foundation.h>

@interface WeakEncryptionHash : NSObject
-(void) test;
@end

@implementation WeakEncryptionHash
-(void) test {
NSString *urlString = @"http://yourserver.com/upload.php";
NSString *filename = @"filename";
request= [[[NSMutableURLRequest alloc] init] autorelease];
[request setURL:[NSURL URLWithString:urlString]];
[request setHTTPMethod:@"POST"];
NSString *boundary = @"---------------------------14737809831466499882746641449";
NSString *contentType = [NSString stringWithFormat:@"multipart/form-data; boundary=%@",boundary];
[request addValue:contentType forHTTPHeaderField: @"Content-Type"];
NSMutableData *postbody = [NSMutableData data];
[postbody appendData:[[NSString stringWithFormat:@"\r\n--%@\r\n",boundary] dataUsingEncoding:NSUTF8StringEncoding]];
[postbody appendData:[[NSString stringWithFormat:@"Content-Disposition: form-data; name=\"userfile\"; filename=\"%@.jpg\"\r\n", filename] dataUsingEncoding:NSUTF8StringEncoding]];
[postbody appendData:[[NSString stringWithString:@"Content-Type: application/octet-stream\r\n\r\n"] dataUsingEncoding:NSUTF8StringEncoding]];
[postbody appendData:[NSData dataWithData:YOUR_NSDATA_HERE]];
[postbody appendData:[[NSString stringWithFormat:@"\r\n--%@--\r\n",boundary] dataUsingEncoding:NSUTF8StringEncoding]];
[request setHTTPBody:postbody];

NSData *returnData = [NSURLConnection sendSynchronousRequest:request returningResponse:nil error:nil];
returnString = [[NSString alloc] initWithData:returnData encoding:NSUTF8StringEncoding];
NSLog(@"%@", returnString);
}
@end
