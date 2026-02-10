
/* II_007 - invalid range2 */

#include <algorithm>
#include <iostream>
#include <vector>

void II_007_function(const std::vector<int> &c) {
  std::vector<int>::const_iterator e;
  std::for_each(c.begin(), e, [](int i) { //@violation INVALID_ITERATOR
    std::cout << i; 
  });
}
