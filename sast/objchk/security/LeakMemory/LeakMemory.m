

#import <Foundation/Foundation.h>
#define BLOCK_SIZE 1024
#define N 25
@interface ProperMemoryRelease : NSObject
-(NSString *) dynamicAllocation;
-(NSString *) dynamicAllocation_bad;
@end



char* getBlock_bad (int fd) {
  char *buf = (char*) malloc (BLOCK_SIZE);
  if (!buf) { return NULL; }
  if (read(fd, buf, BLOCK_SIZE) != BLOCK_SIZE) {
    return NULL;             // @violation
  }
  return buf;
}


char* getBlock (int fd) {
  char *buf = (char*) malloc (BLOCK_SIZE);
  if (!buf) { return NULL; }
  if (read(fd, buf, BLOCK_SIZE) != BLOCK_SIZE) {
    free (buf);
    return NULL;
  }
  return buf;
}


@implementation ProperMemoryRelease
-(NSString *) dynamicAllocation_bad
{
	NSObject *anObj = [[NSObject alloc] init];
	NSMutableArray *array = [[NSMutableArray alloc] initWithCapacity:N];
	// anObj를 가지고 작업 수행
	return 0;// @will-violation

}

-(NSString *) dynamicAllocation9
{
	NSObject *anObj = [[NSObject alloc] init];
	NSMutableArray *array = [[NSMutableArray alloc] initWithCapacity:N];
	// anObj를 가지고 작업 수행
	[anObj release];
	[array release];
	return 0;
}
@end





