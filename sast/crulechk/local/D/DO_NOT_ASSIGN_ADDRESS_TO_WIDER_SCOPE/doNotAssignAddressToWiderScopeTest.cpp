//@checker DO_NOT_ASSIGN_ADDRESS_TO_WIDER_SCOPE


//TC1
int *p1;   

void func()  
{ 
	static int localNum =3;  
	p1 = &localNum;   //compliant
}



//TC2
int globalNum = 2;  

void func2()  
{
	static int *p2;  
	p2 = &globalNum;    //compliant
}



//TC3
static int staticGlobalNum = 3; 

void func3()  
{
	static int *p3;       
	p3 = &staticGlobalNum;  //compliant
}


//TC4
int *pNum;

void func4()
{
	int num;
	pNum = &num;  //@violation DO_NOT_ASSIGN_ADDRESS_TO_WIDER_SCOPE
}



//TC5
void func5()
{
	if (true)
	{
		{
			int *pNum;
			{
				{
					int num;
					pNum = &num;  //@violation DO_NOT_ASSIGN_ADDRESS_TO_WIDER_SCOPE
				}
			}
		}
	}
}