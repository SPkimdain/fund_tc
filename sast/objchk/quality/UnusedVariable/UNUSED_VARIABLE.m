#import <Foundation/Foundation.h>




int aa(int* a)
{
	a = 0;
}

@interface MyObj: NSObject {
@private
  int x; // will-violation
}
@end
@implementation MyObj
@end




@interface MyObj2 : NSObject {
@private
  int x; 
  int y; // will-violation
    
    
}
-(id) test1;
-(void) sendError:(NSError *)e ;
@end



@implementation MyObj2
-(id) init {
    self = [super init];

    self.x = 1;

    return self;
}
-(id) test1 {

int test;

aa(&test);

return self;
}

- (void)sendError:(NSError *)e {
		    

			
			 for (id object in array) {
		            [newArray addObject:(object == NSNull.null ? RACTupleNil.tupleNil : object)];
		        }
		       


		}
@end


