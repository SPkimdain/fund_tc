
/* II_004 - vector, push_back */
#include <vector>
#include <iostream>

void II_004_function() {  
  std::vector<int> vec;
  
  vec.push_back(10);
  
  auto&& iter = vec.begin();

  vec.push_back(20);
  //iter is invalid iterator.
  
  std::cout << *iter << std::endl; //@violation INVALID_ITERATOR  
}

