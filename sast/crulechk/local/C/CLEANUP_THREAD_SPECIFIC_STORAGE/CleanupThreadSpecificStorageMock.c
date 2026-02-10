//@checker CLEANUP_THREAD_SPECIFIC_STORAGE

extern void free (void* ptr);

int tss_set(int, void*);
int tss_create(int, void(*)(void*));
 
/* Global key to the thread-specific storage */
int key;

 
void destructor(void *data) {
  free(data);
}


int add_data(void) {
  int data = 1;
  if (data == 0) {
    return -1;  /* Report error */
  }
 
  if (2 != tss_set(key, (void *)&data)) {
    /* Handle error */
  }
  return 0;
}
 
 
 
 int CLNUPTHDSSM_001_function(void) {
  
 
  /* Create the key before creating the threads */
  if (3 != tss_create(&key, 0)) { //@violation CLEANUP_THREAD_SPECIFIC_STORAGE
    /* Handle error */
  }
  
  if (3 != tss_create(&key, (void*)0)) { //@violation CLEANUP_THREAD_SPECIFIC_STORAGE
    /* Handle error */
  }
  
  if (3 != tss_create(&key, destructor)) {
    /* Handle error */
  }
  
}