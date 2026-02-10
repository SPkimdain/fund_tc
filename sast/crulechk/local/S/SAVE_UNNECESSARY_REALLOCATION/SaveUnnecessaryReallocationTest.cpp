//@checker SAVE_UNNECESSARY_REALLOCATION

#include <vector>

using namespace std;

class Test
{
public:
	void foo()
	{
		mVec.push_back( 10 );
	}
private:
	vector<int> mVec;
};


void badPushBackManyNumbers( vector< int >& vec )
{
	// This code may result in the vector increasing
	// its capacity several times.
	//
	for ( int i = 0; i < 100; ++i )
	{
		vec.push_back( i ); //@violation SAVE_UNNECESSARY_REALLOCATION
	}

	int x = 0;
	vector<int> vec2;
	while( x < 10 )
	{
		//while문의 경우는 예외로 함(반복문 특성상 끝점이 확실치 않은 경우가 많음)
		vec2.push_back( x ); 
		x++;
	}

	if( x == 10 )
	{
		for( int i = 0; i < 100; i++ )
		{
			vec2.push_back( i ); //@violation SAVE_UNNECESSARY_REALLOCATION
		}
	}
}

void goodPushBackManyNumbers( vector< int >& vec )
{
	// This code cleverly preallocates so the vector only
	// increases its capacity once.
	//
	int x = 10;
	if( x == 10 )
	{
		vec.reserve( vec.size() + 100 );
		for ( int i = 0; i < 100; ++i )
		{
			vec.push_back( i );
		}
	}

	for( int i = 0; i< 100; i++ )
	{
		vec.push_back( i ); //@violation SAVE_UNNECESSARY_REALLOCATION
	}
}

int main()
{

	return 1;
}
