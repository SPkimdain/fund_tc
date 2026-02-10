//@checker PRESERVE_ARRAY_DIMENSION

extern int* PSARRDIM_004_wrap();
extern int* PSARRDIM_004_wrap2(int* p2);
extern void PSARRDIM_004_call(int *p);

struct PSARRDIM_004_Struct {
  int arr[10];
};

void PSARRDIM_004_function(PSARRDIM_004_Struct* obj) {
  ;

  PSARRDIM_004_call(
    PSARRDIM_004_wrap2(obj->arr)); //@violation PRESERVE_ARRAY_DIMENSION

  int* ptr = obj->arr;

  PSARRDIM_004_call(
    PSARRDIM_004_wrap2(ptr)); //It's ok.
	 

}
