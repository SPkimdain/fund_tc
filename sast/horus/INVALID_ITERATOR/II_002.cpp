
/* II_002 - deque, insert */

#include <deque>

void II_002_function(const double *items, std::size_t count) {
  
  std::deque<double> d;
  
  auto pos = d.begin();
  
  for(std::size_t i = 0; i < count; ++i, ++pos) {  //@violation INVALID_ITERATOR
    d.insert(pos, items[i] + 41.0);
  }

}


