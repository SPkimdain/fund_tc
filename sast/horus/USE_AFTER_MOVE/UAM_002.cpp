#include <iostream>
#include <string>

/* UAM_002 - simple case 2 */

unsigned UAM_002_function() {
  std::string s1;
  std::string s2;
  
  s1 = "1231234123";

  s2 = std::move(s1);
  
  return s1.size(); //@violation USE_AFTER_MOVE
}

