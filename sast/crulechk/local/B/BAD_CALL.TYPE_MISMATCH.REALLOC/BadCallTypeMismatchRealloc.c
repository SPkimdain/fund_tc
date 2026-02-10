// @checker BAD_CALL.TYPE_MISMATCH.REALLOC
extern void* realloc (void* ptr, int size);

typedef struct gadget gadget;
struct gadget {
  int i;
  double d;
  char *p;
};
 
typedef struct widget widget;
struct widget {
  char *q;
  int j;
  double e;
};

void foo()
{
	gadget *gp;
	widget *wp;

  wp = (widget *)realloc(wp, sizeof(widget));
	wp = (widget *)realloc(gp, sizeof(widget));	// @violation BAD_CALL.TYPE_MISMATCH.REALLOC
}

