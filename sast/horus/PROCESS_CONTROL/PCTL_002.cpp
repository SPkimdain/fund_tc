#include <stdlib.h>

#ifdef _WIN32

#include <windows.h>

#else

typedef void* HANDLE;
#define CreateMutex CreateMutexA

extern HANDLE CreateMutexA(void* attr, bool init, const char* lpName);

extern unsigned long WaitForSingleObject(HANDLE mutex, unsigned long ms);

extern bool ReleaseMutex(HANDLE mutex);

extern bool CloseHandle(HANDLE mutex);

#define LoadLibrary LoadLibraryA

extern void* LoadLibraryA(const char* fileName);

#endif

/* PCTL_002 - simple case, windows */
void PCTL_002_function2(char* filename) {
  LoadLibrary(filename);
}

void PCTL_002_function() {
  char *filename;
  filename = getenv("SHAREDFILE");

  PCTL_002_function2(filename); //@violation PROCESS_CONTROL

  return;
}
