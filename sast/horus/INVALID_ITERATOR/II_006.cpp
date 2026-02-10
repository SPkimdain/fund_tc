
/* II_006 - invalid range */

#include <algorithm>
#include <iostream>
#include <vector>

void II_006_function(const std::vector<int> &c) {
  std::for_each(c.end(), c.begin(), [](int i) { //@violation INVALID_ITERATOR
    std::cout << i; 
  }); 
}
