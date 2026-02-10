#include <list>

using namespace std;

/* LM_034 - container: list */
void LM_034_function1(list<char*>& x) {
  char* data = new char[100]();
  x.push_front(data);
  return; //It's ok.
}

void LM_034_function2(list<char*>& x, bool flag) {
  char* data = new char[50]();
  if(flag == true) {
    x.push_front(data);
  }

  //else branch
  return;
} //@violation LEAK.MEMORY
