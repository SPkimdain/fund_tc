//@checker DO_NOT_MODIFY_PRIVATE_IN_PUBLIC_FUNCTION
//from http://cwe.mitre.org/data/definitions/767.html

int *global = new int[3];
int glob = 3;
class A 
{
	
private:
	int* intStr;
	int stock;
	void setvoidarr(int *a);
	
public :
	void setarray(int* intStr)
	{
		this->intStr = intStr; //@violation DO_NOT_MODIFY_PRIVATE_IN_PUBLIC_FUNCTION
	}
	
	void setarr2(int * a);
	void setarr3(int * a, int c);
	
	
};

void A::setvoidarr(int *a)
{
	intStr = a; // FP case
}


void A::setarr2(int * a)
{
	intStr = a; //@violation DO_NOT_MODIFY_PRIVATE_IN_PUBLIC_FUNCTION
	intStr = global; //@violation DO_NOT_MODIFY_PRIVATE_IN_PUBLIC_FUNCTION
	stock = glob; //diff cwe-496 //@violation DO_NOT_MODIFY_PRIVATE_IN_PUBLIC_FUNCTION
}

void A::setarr3(int * a, int c)
{
	int * b = new int(*a);
	intStr = b;  //diff cwe-496  //@violation DO_NOT_MODIFY_PRIVATE_IN_PUBLIC_FUNCTION
	stock = c; //diff cwe-496 //@violation DO_NOT_MODIFY_PRIVATE_IN_PUBLIC_FUNCTION
}


