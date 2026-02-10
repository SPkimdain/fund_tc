//@checker FORBIDDEN_CALL.LOOP
extern void* malloc (int size);
extern void * memcpy ( void * destination, const void * source, int num );
extern void free (void* ptr);

int array_swap(char * left[], char * right[], int count,
                         int buf_size){
  char * temp = 0;
  int i = 0;
  for (i = 0; i < count; i ++) {
    temp = (char *)malloc(buf_size); //@violation FORBIDDEN_CALL.LOOP
    memcpy(left[i], temp, buf_size);
    memcpy(right[i], left[i], buf_size);
    memcpy(temp, right[i], buf_size);
    free(temp);
  }
  return count;
}