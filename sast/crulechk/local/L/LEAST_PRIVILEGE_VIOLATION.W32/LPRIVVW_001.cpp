//@checker LEAST_PRIVILEGE_VIOLATION.W32

#define SHREGSET_HKLM 0x00000004
#define ERROR_SUCCESS 2
#define KEY_WRITE 3

typedef void* HANDLE;

extern int SHRegCreateUSKeyA(char* name, int flag, void* check, HANDLE* key, int val);

int LPRIVVW_001_function(char* keyName) {
  HANDLE hKey;
  
  if(SHRegCreateUSKeyA(keyName, KEY_WRITE, 0, &hKey, SHREGSET_HKLM) != ERROR_SUCCESS) { //@violation LEAST_PRIVILEGE_VIOLATION.W32
    return 0;
  }
    
  return 1;
}
