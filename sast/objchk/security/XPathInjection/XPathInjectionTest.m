#import <Foundation/Foundation.h>
#import <libxml/xpath.h>

int xpathTestFunction() {
    NSString* str = getenv("source");

    xmlXPathContextPtr xpathCtx;
    NSString *query = str;

    xpathCtx = xmlXPathNewContext(doc);

    xmlChar *queryStr = (xmlChar *)[query cStringUsingEncoding:NSUTF8StringEncoding];
    xpathObj = xmlXPathEvalExpression(queryStr, xpathCtx); //@violation

    return 0;
}
