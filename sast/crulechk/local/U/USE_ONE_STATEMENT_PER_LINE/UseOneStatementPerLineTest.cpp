//@checker USE_ONE_STATEMENT_PER_LINE

#define TEST int x=0; int y=0;
#define TEST2(y) for(int i=0;i<10;i++)		\
	{										\
		y += i;								\
		y--;								\
	}



int main()
{
	int n = 10; float m = 50.F; //@violation USE_ONE_STATEMENT_PER_LINE

	TEST; //False Alarm

	TEST2(n); //False Alarm

	while(x < 10) x++;

	x = 0;

	while(x < 10){ x++; y++; } //@violation USE_ONE_STATEMENT_PER_LINE

	x = 0;
	do { x++; } while(x<10);

	do { x++; y++; } while(x<10); //@violation USE_ONE_STATEMENT_PER_LINE
}


