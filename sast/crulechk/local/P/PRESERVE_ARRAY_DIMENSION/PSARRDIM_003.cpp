//@checker PRESERVE_ARRAY_DIMENSION

extern int* PSARRDIM_003_wrap();
extern int* PSARRDIM_003_wrap2(int* p2);
extern void PSARRDIM_003_call(int *p);

void PSARRDIM_003_function() {
	int a[10];

  PSARRDIM_003_call(PSARRDIM_003_wrap()); //It's ok.

  PSARRDIM_003_call(
    PSARRDIM_003_wrap2(a)); //@violation PRESERVE_ARRAY_DIMENSION
	
  PSARRDIM_003_wrap2(PSARRDIM_003_wrap()); //It's ok.

}
