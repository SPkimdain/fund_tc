// @checker CAST_AFTER_MEM_ALLOC

extern void* malloc (int size);
extern void free (void* ptr);

typedef struct gadget gadget;
struct gadget {
  int i;
  double d;
};
 
typedef struct widget widget;
struct widget {
  char c[10];
  int i;
  double d;
};
 
void CASTAMA_001_function()
{
	widget *p;
	 /* ... */
	void *ptr = 0;
	ptr = malloc(sizeof(gadget)); //@violation CAST_AFTER_MEM_ALLOC
	
  widget* ptr2 = (widget*) malloc(sizeof(gadget));

  free(ptr);
  free(ptr2);
}
