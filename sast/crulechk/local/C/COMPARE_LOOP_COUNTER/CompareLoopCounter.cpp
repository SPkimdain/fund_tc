//@checker COMPARE_LOOP_COUNTER
#include <set>
using namespace std;

void CompareLoopCounter()
{ 
	int i = 0 ;
	
	for( i =1 ; i != 10 ; i += 2) //@violation COMPARE_LOOP_COUNTER
	{
		
	}
	
	for( i =1 ; i <= 10 ; i += 2)
	{
		
	}
	
	
	for( i =1 ; i != 10 ; i ++ )
	{
		
	}
	
	set<int> s;
	set<int>::iterator iter, iterStart, iterEnd;
	iterStart = s.begin();
	iterEnd = s.end();
	
	for(iter = iterStart; iter != iterEnd; iter++)
	{
		
	}
}