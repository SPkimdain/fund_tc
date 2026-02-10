// @checker USE_TYPEREF_NON_POINTER_TYPE

typedef int (*fptr)(int len);
int (*fptr1)(int len);

struct foo {
  int i;
  float f;
};
typedef struct obj *ObjectPtr;	//@violation USE_TYPEREF_NON_POINTER_TYPE
typedef struct obj Object;

int test();
 
void bar(const ObjectPtr o) {
  /* Can actually modify o's contents, against expectations. */
	
}