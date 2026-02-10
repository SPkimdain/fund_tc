//@checker USE_EMPTY_INSTEAD_OF_CHECKING_SIZE_AGAINST_ZERO

#include <list>

void foo() {
  std::list< int > myList;
  if ( false == myList.empty() )   // constant time test
  {}
  
  if ( 0 == myList.size() )        //@violation USE_EMPTY_INSTEAD_OF_CHECKING_SIZE_AGAINST_ZERO
  {    
  }
}
