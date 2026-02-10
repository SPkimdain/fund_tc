#import <NSObjCRuntime.h>
void foo()  {
char* path=getenv("MYPATH");     // 오류가 발생하는 경우
NSLog(@"파일 경로를 찾을 수 없습니다. 경로:%s\n",path); //@violation
}



@interface LogForging : NSObject
+(char *) mGetSource;
@end

@implementation LogForging
+(char *) mGetSource {
   @try
   {

   }
   @catch(NSException *exception)
   {
    NSLog(@"paser err : %@",[exception description]);//@violation
   }
}
@end