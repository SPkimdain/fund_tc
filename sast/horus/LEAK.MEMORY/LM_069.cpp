
extern void* HeapAlloc(void* hHeap, unsigned int dwFlags, unsigned int dwBytes);

/* LM_069 - 3rd party leak memory. */
void LM_069_function() {
  int * ptr = (int*)HeapAlloc(0, 0, 1024);
} //@violation LEAK.MEMORY

