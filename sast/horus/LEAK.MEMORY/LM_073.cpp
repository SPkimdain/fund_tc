#include <map>
#include <string>
#include <memory.h>

using namespace std;

/* LM_073 - map check. */
int LM_073_function(std::map<string, int*>& container, const string& key, int size) {
  int* datas = new int[size]();
  memset(datas, 0, size * sizeof(int));
  if(key.compare("invalide") != 0) {
    container.insert(std::make_pair(key, datas));
    return 0;
  }

  return -1;
} //@violation LEAK.MEMORY
