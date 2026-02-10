@implementation test
- (BOOL) compareTrucks: (Truck) b {
return (self == b); // @violation
}
@end
