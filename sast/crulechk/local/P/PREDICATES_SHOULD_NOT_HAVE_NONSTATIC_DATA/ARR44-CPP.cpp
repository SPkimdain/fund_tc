//@checker PREDICATES_SHOULD_NOT_HAVE_NONSTATIC_DATA
#include <iostream>
#include <functional>
#include <vector>
#include <algorithm>

using namespace std;

class BadPredicate: public unary_function<int, bool> {
public:
  BadPredicate() : timesCalled(0) {}
  bool operator()(const int&) {
    return ++timesCalled == 3;
  }
private:
  size_t timesCalled; //@violation PREDICATES_SHOULD_NOT_HAVE_NONSTATIC_DATA
};

int main () {
  vector<int> v;
  for (int i = 0; i < 10; i++) v.push_back(i);
  cout << "Vector contains:";
  for (vector<int>::iterator it = v.begin(); it != v.end(); ++it)
    cout << " " << *it;
  cout << endl;
 
  v.erase( remove_if( v.begin(), v.end(), BadPredicate()), v.end());
  cout << "Vector contains:";
  for (vector<int>::iterator it = v.begin(); it != v.end(); ++it)
    cout << " " << *it;
  cout << endl;
 
  return 0;
}
