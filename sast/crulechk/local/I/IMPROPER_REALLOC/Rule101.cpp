//@checker IMPROPER_REALLOC

typedef long size_t;
extern void* realloc (void* ptr, size_t size);

void IMPROREALLOC_001_function(int * p) 
{
  p = (int*)realloc(p, 10); // @violation IMPROPER_REALLOC
}

void IMPROREALLOC_001_function2(int * p, int x) 
{

  if(x == 5)
  {
    p = (int*)realloc(p, 10); // @violation IMPROPER_REALLOC
  }
  *p = 10;
}

int* IMPROREALLOC_001_function3(int *p) {
  int *newP;
  newP = (int*)realloc(p, 10);
  return 0;
}
