//@checker ENSURE_EACH_IDENTIFIER_IS_DISTINCT

class C //@b-violation ENSURE_EACH_IDENTIFIER_IS_DISTINCT
{
public:
	C() {}
	void foo()
	{
		x = 10;
	}
private:
	int x;
};

typedef struct _Test
{
	int x;
	int y;
} Test ; //@b-violation ENSURE_EACH_IDENTIFIER_IS_DISTINCT

typedef float FLOATING; //@b-violation ENSURE_EACH_IDENTIFIER_IS_DISTINCT

int bar()
{
	int C; //@violation ENSURE_EACH_IDENTIFIER_IS_DISTINCT
	int TEST2;
	return 10;
}

struct Test2 //@b-violation ENSURE_EACH_IDENTIFIER_IS_DISTINCT
{
	int z;
	int k;
};

int main()
{
	int C; //@violation ENSURE_EACH_IDENTIFIER_IS_DISTINCT
	int Test; //@violation ENSURE_EACH_IDENTIFIER_IS_DISTINCT
	int FLOATING; //@violation ENSURE_EACH_IDENTIFIER_IS_DISTINCT
	int Test2; //@violation ENSURE_EACH_IDENTIFIER_IS_DISTINCT
	//FLOATING x;
	//C cc; 
	//Test2 t2;
}

