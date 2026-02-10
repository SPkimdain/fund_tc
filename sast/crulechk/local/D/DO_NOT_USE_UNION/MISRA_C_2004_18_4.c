// @checker DO_NOT_USE_UNION

union A // @violation DO_NOT_USE_UNION
{

	int var1;
	double var2;
	char var3;

};

 

int main(void) 
{
	union A uni;                        
}
