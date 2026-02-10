//@checker STRING_OUT_OF_RANGE
#include <string>
#include <locale>

extern std::size_t get_index();
extern std::size_t get_char();
  
void f() {
  std::string s("01234567");
  get_char();
  s[0] = '1'; //@violation STRING_OUT_OF_RANGE
  s[get_index()] = '1'; //@violation STRING_OUT_OF_RANGE
}


void f_safe() {
  std::string s("01234567"); 
  std::size_t i = get_index();
  // std::size_t ia = s.length();
  if (i < s.length()) {
    s[i] = '1';
  } else {
    // Handle error
  }
}



void capitalize(std::string &s) {
  std::locale loc;
  s.front() = std::use_facet<std::ctype<char>>(loc).toupper(s.front()); //@violation STRING_OUT_OF_RANGE
}



void capitalize_safe(std::string &s) {
  if (s.empty()) {
    return;
  }
 
  std::locale loc;
  s.front() = std::use_facet<std::ctype<char>>(loc).toupper(s.front());
}
