#import <Foundation/Foundation.h>

#define MAX_STR 100

int f()
{
    char cstr[MAX_STR];

    scanf("%s", cstr);
    NSString *str = [NSString stringWithCString: cstr encoding: [NSString defaultCStringEncoding]]; // @violation


    id myObj = [[NSClassFromString(str) alloc] init]; // @violation
    // ...
}



@interface UnsafeReflection : NSObject
+(char *) mGetSource;
+(char *) mGetSource2Step:(int)a;
+(NSString *)getQuery:(NSURL *)url;
@end

@implementation UnsafeReflection
+(char *) mGetSource {
    return getenv("SOURCE");
}
+(char *) mGetSource2Step:(int)a {
    if(a > 0) {
        return getenv("SOURCE");
    } else {
        return NULL;
    }
}
+ (NSString *)getQuery: (NSURL *)url {
    return [url query];
}
- (void)func: (NSURL *)url {
    NSString * query = [url query];
    NSString * pathExtension = [url pathExtension];
    NSString * query2 = [UnsafeReflection getQuery: url];
    
    [self performSelector: NSSelectorFromString(pathExtension) withObject: query]; // @violation
    [self performSelector: NSSelectorFromString(pathExtension) withObject: query2]; // @violation





}
@end


