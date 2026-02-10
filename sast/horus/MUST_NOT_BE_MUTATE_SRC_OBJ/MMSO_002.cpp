#include <algorithm>
#include <vector>

/* MMSO_002 - simple case2 */

class MMSO_002 {
  mutable int m;

public:
  MMSO_002() : m(0) {}
  explicit MMSO_002(int m) : m(m) {}

  MMSO_002(const MMSO_002 & other) : m(other.m) {
  }

  MMSO_002& operator=(const MMSO_002& other) {
    if(&other != this) {
      m = other.m;
      other.m = 0;  //@violation MUST_NOT_BE_MUTATE_SRC_OBJ
    }
    return *this;
  }

};

void MMSO_002_function1() {
  std::vector<MMSO_002> v { 10 };
  MMSO_002 obj(12);
  std::fill(v.begin(), v.end(), obj);
}
