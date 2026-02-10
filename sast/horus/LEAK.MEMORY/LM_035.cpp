#include <vector>

using namespace std;

/* LM_035 - container: vector */
 void LM_035_function1(vector<char*>& x) {
   char* data = new char[100]();
   x.push_back(data);
   return; //It's ok.
 }

void LM_035_function2(vector<char*>& x, bool flag) {
  char* data = new char[50]();
  if(flag == true) {
    x.push_back(data);
  }

  //else branch
  return;
} //@violation LEAK.MEMORY
