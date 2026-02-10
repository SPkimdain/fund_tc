
/* II_003 - string, insert */
#include <string>

void II_003_function(const std::string &input) {
  std::string email;

  // Copy input into email converting ";" to " "
  std::string::iterator loc = email.begin();
  
  for(auto i = input.begin(), e = input.end(); i != e; ++i, ++loc) { //@violation INVALID_ITERATOR
    email.insert(loc, *i != ';' ? *i : ' '); 
  }

}

