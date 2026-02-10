
/* IL_003 - simple case3 */

#include <stdio.h>
#include <stdlib.h>

#if _WIN32
#define snprintf _snprintf
#else
#endif /* _WIN32 */

void IL_003_function(){
  char* path = getenv("PATH");
  char buf[256] = { 0, };
  snprintf(buf, 256, "%s", path); //@violation INFORMATION_LEAK
}

