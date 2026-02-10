#include <stdlib.h>
#include <memory>
#include <cstring>

/* MR_006 - copy assign operator - missing return */
class MR_006_Class {
public:
  MR_006_Class() : length(0), data(0) {}
  MR_006_Class(size_t len) {
    length = len;
    data = new char[len]();
  }

  ~MR_006_Class() {
    delete[] data;
  }

  MR_006_Class& operator=(const MR_006_Class& rhs) {
    if(this != &rhs) {
      delete[] data;
      data = new char[rhs.length]();
      length = rhs.length;
      memcpy(data, rhs.data, sizeof(char) * length);
    }
  } //@violation MISSING_RETURN

private:
  size_t length;
  char* data;
};
