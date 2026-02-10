#include <set>

using namespace std;

/* LM_036 - container: set */
 void LM_036_function1(set<char*>& x) {
   char* data = new char[100]();
   x.insert(data);
   return; //It's ok.
 }

void LM_036_function2(set<char*>& x, bool flag) {
  char* data = new char[50]();
  if(flag == true) {
    x.insert(data);
  }

  //else branch
  return;
} //@violation LEAK.MEMORY
