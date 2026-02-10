#import <Foundation/Foundation.h>
#include <sqlite3.h>

@interface SqlInjection : NSObject
+(char *) mGetSource;
+(char *) mGetSource2Step:(int)a;
@end

@implementation SqlInjection
+(char *) mGetSource {
    return getenv("QUERY");
}
+(char *) mGetSource2Step:(int)a {
    if(a > 0) {
        return getenv("QUERY");
    } else {
        return NULL;
    }
}
@end

char * getSource() {
    return getenv("QUERY");
}

char * getSource2Step() {
    return getSource();
}

NSString * propagates() {
    return [NSString stringWithUTF8String: getSource()];
}

void func() {
    sqlite3 * db;
    char err[1024];
    int ret;
    ret = sqlite3_exec(db, [SqlInjection mGetSource], NULL, 0, &err); // @violation
    ret = sqlite3_exec(db, [SqlInjection mGetSource2Step: 2], NULL, 0, &err); // @violation
}

int main(int argc, char * argv[]) {
    sqlite3 * db;
    char err[1024];
    char query[1024];
    char query2[1024];
    int ret;
    ret = sqlite3_exec(db, argv[1], NULL, 0, &err); // @violation
    ret = sqlite3_exec(db, getenv("QUERY"), NULL, 0, &err); // @violation
    ret = sqlite3_exec(db, getSource(), NULL, 0, &err); // @violation
    ret = sqlite3_exec(db, getSource2Step(), NULL, 0, &err); // @violation
    ret = sqlite3_exec(db, propagates(), NULL, 0, &err); // @violation
    ret = sqlite3_exec(db, "select * from table", NULL, 0, &err);
    sprintf(query, "%s", getSource()); // Propagator
    ret = sqlite3_exec(db, query, NULL, 0, &err); // @violation
    sprintf(query2, "%s%s", "SELECT *", getSource()); // Propagator
    ret = sqlite3_exec(db, query2, NULL, 0, &err); // @violation
}
