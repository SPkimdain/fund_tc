
/* II_008 - vector, erase */

#include <vector>
#include <iostream>
#include <algorithm>

int II_008_function() {
  std::vector<int> vecArr;
  for(int i = 1; i <= 10; i++) {
    vecArr.push_back(i);
  }

  for(auto it = vecArr.begin(); it != vecArr.end(); it++) {
    std::cout << (*it) << "  ";
  }

  std::cout << std::endl;

  auto it = std::find(vecArr.begin(), vecArr.end(), 5);
  if(it != vecArr.end()) {
    vecArr.erase(it);
  }

  for(; it != vecArr.end(); it++) { 
    std::cout << (*it) << "  "; //@violation INVALID_ITERATOR
  }

  return 0;
}
