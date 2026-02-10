//@checker PRESERVE_ARRAY_DIMENSION

extern int* PSARRDIM_005_wrap();
extern int* PSARRDIM_005_wrap2(int* p2);
extern void PSARRDIM_005_call(int *p);
extern void PSARRDIM_005_int(int data);


void PSARRDIM_005_function() {
  int arr[10] = { 0, };
  
  PSARRDIM_005_int(arr[0]); //It's ok.

  PSARRDIM_005_call(arr); //@violation PRESERVE_ARRAY_DIMENSION
  
  PSARRDIM_005_call(&arr[0]); //It's ok.
}
