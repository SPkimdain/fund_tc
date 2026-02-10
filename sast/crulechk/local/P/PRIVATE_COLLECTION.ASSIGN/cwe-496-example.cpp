//@checker PRIVATE_COLLECTION.ASSIGN
//from http://cwe.mitre.org/data/definitions/495.html

int *global = new int[3];
int glob = 3;
class A 
{
	
private:
	int* intStr;
	int stock;
	
public :
	void setarray(int* intStr)
	{
		this->intStr = intStr; //@violation PRIVATE_COLLECTION.ASSIGN
	}
	
	void setarr2(int * a);
	void setarr3(int * a, int c);
	
	
};


void A::setarr2(int * a)
{
	intStr = a; //@violation PRIVATE_COLLECTION.ASSIGN
	intStr = global; //@violation PRIVATE_COLLECTION.ASSIGN
	stock = glob;
}

void A::setarr3(int * a, int c)
{
	int * b = new int(*a);
	intStr = b; 
	stock = c;
}


