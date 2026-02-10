#ifdef _WIN32

#include <windows.h>

#else

typedef void* HANDLE;
#define CreateMutex CreateMutexA

extern HANDLE CreateMutexA(void* attr, bool init, const char* lpName);

extern unsigned long WaitForSingleObject(HANDLE mutex, unsigned long ms);

extern bool ReleaseMutex(HANDLE mutex);

extern bool CloseHandle(HANDLE mutex);

#define INFINITE            0xFFFFFFFF

#endif

/* DL_003 - simple case3, linux */


int DL_003_lock(HANDLE hMutex) {
  WaitForSingleObject(hMutex, INFINITE);
  return 0;
}

int DL_003_function(HANDLE hMutex, int flag, int flag2) {
  DL_003_lock(hMutex);

  if(flag > 10) {
    if(flag2 == 100) {
      DL_003_lock(hMutex); //@violation DOUBLE_LOCK
    }
  }

  ReleaseMutex(hMutex);

  return 0;
}

