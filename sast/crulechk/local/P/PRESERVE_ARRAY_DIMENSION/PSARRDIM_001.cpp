//@checker PRESERVE_ARRAY_DIMENSION

void PSARRDIM_001_F1(int p[10]);
void PSARRDIM_001_F2(int *p);
void PSARRDIM_001_F3(int (&p)[10]);

void PSARRDIM_001_function()
{
	int a[10];
  int* ptr = a;
  PSARRDIM_001_F1(ptr); //It's ok.

	PSARRDIM_001_F1(a); //@violation PRESERVE_ARRAY_DIMENSION
	PSARRDIM_001_F3(a);
	
}
