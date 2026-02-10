//@checker DO_NOT_USE_RESTRICT
void vadd(const int* restrict px, const int* restrict py, int* restrict pz, int N) //@violation DO_NOT_USE_RESTRICT
{
	int a = 10;
	int* restrict p1 = &a;//@violation DO_NOT_USE_RESTRICT
	
   for (int i = 0; i < N; ++i)
    *pz++ = *px++ + *py++;
}
