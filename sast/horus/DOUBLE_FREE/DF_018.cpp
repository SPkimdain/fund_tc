
extern void* LocalFree(void* hMem);

/* DF_018 - 3rd party2. */
int DF_018_function(void* mem) {
  LocalFree(mem);
  LocalFree(mem); //@violation DOUBLE_FREE
  return 1;
}

