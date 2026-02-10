#import <Foundation/Foundation.h>

@interface DownloadOfCodeWithoutIntegrityCheckTest : NSObject
-(void) integrityTest;
-(void) integritySafeTest;
@end

@implementation DownloadOfCodeWithoutIntegrityCheckTest
-(void) integrityTest() {
    NSString *stringURL = @"http://www.somewhere.com/thefile.png";
    NSURL  *url = [NSURL URLWithString:stringURL];
    NSData *urlData = [NSData dataWithContentsOfURL:url];
    if(urlData) {
      NSArray       *paths = NSSearchPathForDirectoriesInDomains(NSDocumentDirectory, NSUserDomainMask, YES);
      NSString  *documentsDirectory = [paths objectAtIndex:0];

      NSString  *filePath = [NSString stringWithFormat:@"%@/%@", documentsDirectory,@"filename.png"];
      [urlData writeToFile:filePath atomically:YES]; //@violation
    }
}

-(void) integritySafeTest() {
    NSString *stringURL = @"http://www.somewhere.com/thefile.png";
    NSURL  *url = [NSURL URLWithString:stringURL];
    NSData *urlData = [NSData dataWithContentsOfURL:url];
    if(urlData) {
      NSArray       *paths = NSSearchPathForDirectoriesInDomains(NSDocumentDirectory, NSUserDomainMask, YES);
      NSString  *documentsDirectory = [paths objectAtIndex:0];

      checkIntegrity(urlData);

      NSString  *filePath = [NSString stringWithFormat:@"%@/%@", documentsDirectory,@"filename.png"];
      [urlData writeToFile:filePath atomically:YES];
    }
}

@end
