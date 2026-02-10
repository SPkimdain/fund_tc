// U190.m

#include <stdlib.h>
#import <Foundation/NSObject.h>
#import <Foundation/NSArray.h>
NSMutableArray* maAlloc(int size, int reserve)
{
      size += reserve;
      if(size > 0 )
      {
      //NSMutableArray *rptr = NSMutableArray.arrayWithCapacity(size);
        NSMutableArray *rptr = malloc(size);
      }
      else
      {
        NSMutableArray *rptr = malloc(size); //@will-violation
      }
      if (rptr == NULL)
       exit(1);
      return rptr;
}
