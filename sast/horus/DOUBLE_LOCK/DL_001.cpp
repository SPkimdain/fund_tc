#include <stdio.h>

#ifdef _WIN32

#include <windows.h>

#else

#ifndef FALSE
#define FALSE               0
#endif

#ifndef TRUE
#define TRUE                1
#endif

#define INFINITE            0xFFFFFFFF  // Infinite timeout

typedef void* HANDLE;
#define CreateMutex CreateMutexA

extern HANDLE CreateMutexA(void* attr, bool init, const char* lpName);

extern unsigned long WaitForSingleObject(HANDLE mutex, unsigned long ms);

extern bool ReleaseMutex(HANDLE mutex);

extern bool CloseHandle(HANDLE mutex);

#endif

/* DL_001 - simple case, windows */

int DL_001_function() {
  HANDLE hMutex;
 
  hMutex=CreateMutex(NULL, FALSE, NULL);

  WaitForSingleObject(hMutex, INFINITE);

  WaitForSingleObject(hMutex, INFINITE); //@violation DOUBLE_LOCK

  ReleaseMutex(hMutex);

  CloseHandle(hMutex);

  return 0;
}

