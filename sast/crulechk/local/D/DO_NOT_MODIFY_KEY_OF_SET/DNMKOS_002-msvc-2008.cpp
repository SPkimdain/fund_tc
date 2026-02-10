//@checker DO_NOT_MODIFY_KEY_OF_SET
#include <set>
#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;

int DNMKOS_002_function()
{
  const char* chars="123";
  set<char> container( chars, chars+strlen(chars));

  cout << "chars: ";
  for (set<char>::iterator i = container.begin(); i != container.end(); ++i)
    cout << *i;
  cout << endl;

  for (char c = '1'; c <= '3'; c++) {
    set<char>::iterator x = container.find(c);
    if (x == container.end()) {
      cout << c << " not found" << endl;
      abort();
    }
    // directly changes set contents!
    *x = 'a' + c - '0' - 1;  // @violation DO_NOT_MODIFY_KEY_OF_SET

    cout << "chars: ";
    for (set<char>::iterator i = container.begin(); i != container.end(); ++i)
      cout << *i;
    cout << endl;
  }
  return 0;
}
