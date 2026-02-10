//@checker EMPTY_ARRAY_SIZE.MISRA2012
#define MAX_LENGTH 2

extern int arr[MAX_LENGTH];
extern int arr2[];	//@violation EMPTY_ARRAY_SIZE.MISRA2012

void func() 
{
}