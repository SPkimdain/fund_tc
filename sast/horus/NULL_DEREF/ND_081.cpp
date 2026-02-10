#include <string>

using namespace std;

/* ND_080 - call string ctor with null pointer. */
string ND_080_function(int flag) {
  const char* str = "test";
  const char* str2 = nullptr;

  if(flag > 100) {
    string strValSafe(str); 

    return strValSafe;
  }
  else {
    string strValNullPtr(str2); //@violation NULL_DEREF

    return strValNullPtr;
  }
  
}
