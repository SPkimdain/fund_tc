#include <memory.h>
/* DBZ_058 - memset */

int DBZ_058_function(int value) {
  int arr[100] = { 10, };

  memset(arr, 0, sizeof(int) * 100);
  int ret = value / arr[5]; //@violation DIV_BY_ZERO

  return 0;
}

