//@checker PRIVATE_COLLECTION
//from http://cwe.mitre.org/data/definitions/495.html



class A 
{
	
private:
	int** intArr;
	int * intPtr;	
public :
	int ** getarray()
	{
		return intArr; //@violation PRIVATE_COLLECTION
	}
	int * getarr2();
	int * getarr3();
	int * getarr4();
	int * getarr5();
	
	
};


int * A::getarr2()
{
	return this->intPtr; //@violation PRIVATE_COLLECTION
}

int * A::getarr3()
{
	int * a = this->intPtr;
	return a; //@violation PRIVATE_COLLECTION
}

int * A::getarr4()
{
	int * a= new int(*(this->intPtr));
	return a; 
}


int * A::getarr5()
{
	int * a = this->intPtr;
	int * b = a;
	return b;
}

