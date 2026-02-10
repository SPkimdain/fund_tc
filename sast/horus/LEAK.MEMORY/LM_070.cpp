
extern void* VirtualAllocExNuma(void* hProcess, void* lpAddress, 
  unsigned int dwSize, unsigned int flAllocationType, 
  unsigned int flProtect, unsigned int nndPreferred);

/* LM_070 - 3rd party leak memory2. */
void LM_070_function() {
  int * ptr = (int*)VirtualAllocExNuma(0, 0, 1024, 0, 0, 0);
} //@violation LEAK.MEMORY

