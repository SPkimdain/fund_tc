//@checker NULL_SHALL_NOT_BE_INTERGER_VALUE
#define NULL 0

int NSNBIV_func2(int *);
int NSNBIV_func3(int );

void NSNBIV_func1 (void)
{
	NSNBIV_func3(0);
	NSNBIV_func3(1);
	NSNBIV_func3(NULL);//@violation NULL_SHALL_NOT_BE_INTERGER_VALUE
	NSNBIV_func2(NULL);

}

int NSNBIV_func2(int * zero)
{
	int *p2 =  0; 
	int a = *zero;
	return a;
}

int NSNBIV_func3 (int zero)
{
	int p = zero;
	return p;
}