
/* II_005 - map, erase */

#include <map>

void II_005_function(std::map<int, int>& map) {
  for(auto&& iter = map.begin(), end = map.end(); iter != end; ++iter) { //@violation INVALID_ITERATOR
    map.erase(iter); 
  }
}


