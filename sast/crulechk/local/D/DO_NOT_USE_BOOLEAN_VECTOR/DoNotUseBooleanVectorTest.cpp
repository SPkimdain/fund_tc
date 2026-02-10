//@checker DO_NOT_USE_BOOLEAN_VECTOR

#include <vector>

void foo() {
  std::vector<bool> vec;   //@violation DO_NOT_USE_BOOLEAN_VECTOR
  
  std::vector<bool> //@violation DO_NOT_USE_BOOLEAN_VECTOR
	vec2, vec3; 
}
