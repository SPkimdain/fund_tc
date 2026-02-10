//@checker USE_CONTAINER_MEMBER_FUNCTIONS

#include <set>
#include <vector>
#include <list>
#include <algorithm>
#include <iostream>
#include <iterator>

using namespace std;

int main()
{
	int A[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int nSize = sizeof( A ) / sizeof( int );

	set<int> setInt;

	setInt.clear();
	setInt.insert( 10 );
	setInt.insert( 15 );
	setInt.insert( 20 );
	setInt.insert( 25 );

	setInt.find( 20 );

	find( A, A + nSize, 5 );

	find( setInt.begin(), setInt.end(), 30 ); //@violation USE_CONTAINER_MEMBER_FUNCTIONS

	count( setInt.begin(), setInt.end(), 0 ); //@violation USE_CONTAINER_MEMBER_FUNCTIONS

	vector<double> vecStr;

	vecStr.clear();
	vecStr.push_back( 10 );
	vecStr.push_back( 15 );


	//list계열 컨테이너가 아님
	remove( vecStr.begin(), vecStr.end(), 10 );

	list<int> listInt;
	list<int> listInt2;

	listInt.clear();
	listInt2.clear();

	listInt.push_back( 10 );
	listInt.push_back( 15 );
	listInt.push_back( 20 );
	listInt.push_back( 25 );

	listInt.remove( 10 );

	remove( listInt.begin(), listInt.end(), 10 ); //@violation USE_CONTAINER_MEMBER_FUNCTIONS

	copy( listInt.begin(), listInt.end(), ostream_iterator<int>( cout, " " ) );




	return 1;
}
