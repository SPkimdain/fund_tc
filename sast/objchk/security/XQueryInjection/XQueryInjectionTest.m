#import <Foundation/Foundation.h>
#import <Cocoa/Cocoa.h>

@interface XQueryTest
+(NSArray*) xqueryTestFunction:(NSXMLNode *)node;
@end

@implementation XQueryTest
+(NSArray*) xqueryTestFunction:(NSXMLNode *)node {
    NSString* str = getenv("source");

    NSError* error;
    NSArray* objects;
    NSString *xQuery = str;

    objects = [node objectsForXQuery:xQuery]; //@violation

    return objects;
}
@end
