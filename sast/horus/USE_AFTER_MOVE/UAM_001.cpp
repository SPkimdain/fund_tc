#include <iostream>
#include <string>

/* UAM_001 - simple case 1 */

void UAM_001_function1(std::string && v) {
  std::cout << v << std::endl;
}

void UAM_001_function2() {
  std::string s;
  for(unsigned i = 0; i < 10; ++i) {
    s.append(1, static_cast<char> ('0' + i));  //@violation USE_AFTER_MOVE
    UAM_001_function1(std::move(s));
  }
}

void UAM_001_function3() {
  for(unsigned i = 0; i < 10; ++i) {
    std::string s(1, static_cast<char> ('0' + i));//It's ok.
    UAM_001_function1(std::move(s)); 
  }
}
