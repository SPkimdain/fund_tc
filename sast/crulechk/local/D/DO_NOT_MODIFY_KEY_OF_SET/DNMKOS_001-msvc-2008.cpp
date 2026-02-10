//@checker DO_NOT_MODIFY_KEY_OF_SET

#include <set>
#include <map>
#include <string>
#include <iostream>

using namespace std;

int DNMKOS_001_function()
{
	set<string> strSet;
	set<int> intSet;
	multiset<int> strMultiSet;
	map<string, set<string> > strMap;

	strSet.clear();
	strSet.insert( "Test" );
	strSet.insert( "Apple" );
	strSet.insert( "Bear" );
	strSet.insert( "Customer" );

	strMultiSet.clear();
	strMultiSet.insert( 1 );
	strMultiSet.insert( 1 );
	strMultiSet.insert( 3 );
	strMultiSet.insert( 5 );

	intSet.clear();
	intSet.insert( 1 );

	strMap.clear();
	strMap.insert( make_pair( "Test", strSet ) );

	set<string>::iterator it = strSet.begin();
	multiset<int>::iterator itMulti = strMultiSet.begin();
	map<string, set<string> >::iterator itMap = strMap.begin();
	set<int>::iterator itInt = intSet.begin();

	*it = "Attle"; //@violation DO_NOT_MODIFY_KEY_OF_SET
	*it = string( "Attle" ); //@violation DO_NOT_MODIFY_KEY_OF_SET
	*itMulti = 10; //@violation DO_NOT_MODIFY_KEY_OF_SET
	*itInt = 10; //@violation DO_NOT_MODIFY_KEY_OF_SET

	itMap->second = strSet;
	
	cout << it->c_str() << endl;
	for( ; it != strSet.end(); ++it )
	{
		cout << *it << endl;
	}

	for( ; itMulti != strMultiSet.end(); ++itMulti )
	{
		cout << *itMulti << endl;
	}

}
