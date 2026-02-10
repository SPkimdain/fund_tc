//@checker DO_NOT_ACCESS_OVERLAPPING_STORAGE

union UnionType
{
	short a;
	long long b;
};

struct StructIncludedUnion
{
	UnionType& getUT()
	{
		return this->ut;
	}

	short x;
	int y;
	UnionType ut;
};

int main()
{
	StructIncludedUnion siu1;
	StructIncludedUnion siu2;
	UnionType ut1;
	UnionType ut2;
  int a = 10;

	siu1.x = 1;
	siu1.y = 2;
	siu1.ut.a = 5;
	siu2.x = 3;
	siu2.y = 4;
	siu2.ut.a = 10;

	ut1.a = 10;
	ut2.a = 20;
  
  a = -a;

	ut1.a = ut1.b; //@violation DO_NOT_ACCESS_OVERLAPPING_STORAGE
	
	ut1.a = ut2.b;

	ut1.a = ut1.a; //@violation DO_NOT_ACCESS_OVERLAPPING_STORAGE

	siu1.ut.a = siu1.ut.b; //@violation DO_NOT_ACCESS_OVERLAPPING_STORAGE

	siu1.ut.a = siu2.ut.b;

	siu1.getUT().a = siu1.getUT().b; //@violation DO_NOT_ACCESS_OVERLAPPING_STORAGE

	siu2.getUT().a = siu1.getUT().a;
}



