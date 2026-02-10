//@checker PRESERVE_ARRAY_DIMENSION

void PSARRDIM_002_F1(int p[10]);
void PSARRDIM_002_F2(int *p);
void PSARRDIM_002_F3(int(&p)[10]);

void PSARRDIM_002_function(int inner) {
  float arr[100];

  float x = arr[inner]; //It's ok.

  return;
}


void PSARRDIM_002_functionb()
{
  int a[10];
  PSARRDIM_002_F2(a); //@violation PRESERVE_ARRAY_DIMENSION
  PSARRDIM_002_F3(a);

}
