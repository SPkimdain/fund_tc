#include <algorithm>
#include <vector>

/* MMSO_001 - simple case1 */

class MMSO_001 {
  mutable int m;

public:
  MMSO_001() : m(0) {}
  explicit MMSO_001(int m) : m(m) {}

  MMSO_001(const MMSO_001 & other) : m(other.m) {
    other.m = 0; //@violation MUST_NOT_BE_MUTATE_SRC_OBJ
  }

  MMSO_001& operator=(const MMSO_001& other) {
    if(&other != this) {
      m = other.m;
    }
    return *this;
  }

};

void MMSO_001_function1() {
  std::vector<MMSO_001> v { 10 };
  MMSO_001 obj(12);
  std::fill(v.begin(), v.end(), obj);
}
