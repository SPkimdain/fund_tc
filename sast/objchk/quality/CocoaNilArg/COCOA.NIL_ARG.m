#include <Foundation/Foundation.h>
NSComparisonResult test(NSString *s) {
  NSString *aString = nil;
  return [s caseInsensitiveCompare:aString]; // @violation
    //: argument to 'NSString' method
    // 'caseInsensitiveCompare:' cannot be nil
}
//caseInsensitiveCompare:
//compare:
//compare:options:
//compare:options:range:
//compare:options:range:locale:
//componentsSeparatedByCharactersInSet:
//initWithFormat