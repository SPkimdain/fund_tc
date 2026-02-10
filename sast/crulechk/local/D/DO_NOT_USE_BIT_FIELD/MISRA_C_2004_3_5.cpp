//@checker DO_NOT_USE_BIT_FIELD

class Test 
{
public:
	int x:1; //@violation DO_NOT_USE_BIT_FIELD
	int y;
};

class Test2
{
public:
	int x:1; //@violation DO_NOT_USE_BIT_FIELD
	short y:3; //@violation DO_NOT_USE_BIT_FIELD
	char z:8; //@violation DO_NOT_USE_BIT_FIELD

};

struct Test3 
{
	unsigned char ch:1; //@violation DO_NOT_USE_BIT_FIELD
	int xx:32; //@violation DO_NOT_USE_BIT_FIELD
	float y;
};


int main()
{
	Test t;
	t.x = 5;

}

