// @checker NO_SEMICOLON_ON_SAME_STMT


#define MACROTESTA 11
using namespace std;
const int  TETSA = 10;


void bar(const char* str){
	;
}
class Test
{
	public:
	int a;
	Test* node;
	
};


int getsize(void)
{
	
	
	int compare = 5;
	if ( 
	//asa
		(TETSA == compare ) ||
		(TETSA == compare+1 )
	//aasd


	)
	{
		return 34;
	}
	
	
	if ( 
	//asa
		(MACROTESTA == compare ) ||
		(MACROTESTA == compare+1 ) 
	//aasd


	)
	{
		return 3;
	}
	




	return 5;
}





void foo(int a, int b){
	
	
	if (a == b); return;	//@violation	NO_SEMICOLON_ON_SAME_STMT
	
	
	if (a == b); {	//@violation	NO_SEMICOLON_ON_SAME_STMT
	}

	
	
	
	if (a == b){bar("test");}

	
	while(a != 2); //@violation	NO_SEMICOLON_ON_SAME_STMT
	{
		a++;
	}
	
	
	while(a != 2)
	{
		a++;
	}

	while(b != 2);	//@violation	NO_SEMICOLON_ON_SAME_STMT

	for(int i = 0; i < 10; i++);	//@violation	NO_SEMICOLON_ON_SAME_STMT

	for(int j = 0; j < 10; j++){
		j = j;
	}
	
	
	
	Test t[10];
	Test * c = &(t[0]);
	Test *p;
	for(p = c; p!= 0 ; p = (*p).node ) 	{
		
	}
}
