// @checker DO_NOT_USE_POINTER_ARITHMETIC



int main()
{
	int x, y, z;
	int *px, *py, *pz;
	int i;
	int *p;
	int a[5] = { 10, 20, 30, 40, 50 };
	int **pp;
	x = 0;
	y = 0;
	z = 0;
	px = &x;
	py = &y;
	pz = &z;
	pp = (&a); //*a
	
	//printf( "%d, %d\n", *pz, pz );
	//pz++;
	//printf( "%d, %d\n", *pz, pz );
	
	p = px + 2; // @violation DO_NOT_USE_POINTER_ARITHMETIC
	p = py - 5; // @violation DO_NOT_USE_POINTER_ARITHMETIC
	pz += 1; // @violation DO_NOT_USE_POINTER_ARITHMETIC
	p = pz++; // @violation DO_NOT_USE_POINTER_ARITHMETIC
	i = x * 10;
	p = a - 3; // @violation DO_NOT_USE_POINTER_ARITHMETIC
	i = px[1]; // @violation DO_NOT_USE_POINTER_ARITHMETIC
	i = a[3];
	i = pp[1];// @violation DO_NOT_USE_POINTER_ARITHMETIC
	
	
}
