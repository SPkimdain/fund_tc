//@checker AVOID_FRIEND_FUNCTION_AND_CLASS

void func( int x )
{
}

class Test1
{
public:
	Test1() {}
	~Test1() {}
private:
	int xx;
	int yy;
};

//프렌드 함수, 프렌드 클래스 모두 선언
class Test2 //@violation AVOID_FRIEND_FUNCTION_AND_CLASS
{
	int member;
	friend void func( int x ); 
	friend class Test1;
};

class Test3 //@violation AVOID_FRIEND_FUNCTION_AND_CLASS
{
	int member2;
	friend void func( int x );
};

class Test4 //@violation AVOID_FRIEND_FUNCTION_AND_CLASS
{
	int member3;
	friend class Test2; 
};

int main()
{
	return 1;
}
