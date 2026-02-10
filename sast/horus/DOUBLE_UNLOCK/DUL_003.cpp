#include <stdio.h>

#ifdef _WIN32

#include <windows.h>

#else

#define INFINITE            0xFFFFFFFF  // Infinite timeout

typedef void* HANDLE;
#define CreateMutex CreateMutexA

extern HANDLE CreateMutexA(void* attr, bool init, const char* lpName);

extern unsigned long WaitForSingleObject(HANDLE mutex, unsigned long ms);

extern bool ReleaseMutex(HANDLE mutex);

extern bool CloseHandle(HANDLE mutex);

#endif

/* DUL_003 - simple case3, linux */


int DUL_003_unlock(HANDLE hMutex) {
  ReleaseMutex(hMutex);
  return 0;
}

int DUL_003_function(HANDLE hMutex, int flag, int flag2) {
  WaitForSingleObject(hMutex, INFINITE);

  if(flag > 10) {
    if(flag2 == 100) {
      DUL_003_unlock(hMutex);
    }
  }

  DUL_003_unlock(hMutex);  //@violation DOUBLE_UNLOCK

  return 0;
}

