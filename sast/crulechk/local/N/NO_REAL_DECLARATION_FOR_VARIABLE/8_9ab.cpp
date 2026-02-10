//@checker NO_REAL_DECLARATION_FOR_VARIABLE

int comp1 = 10;

extern int notComp1 = 5;	//@violation NO_REAL_DECLARATION_FOR_VARIABLE

extern int notComp3; 	//@violation NO_REAL_DECLARATION_FOR_VARIABLE

int NRDFV_func2(int kk)
{
	return kk + 10;
}
