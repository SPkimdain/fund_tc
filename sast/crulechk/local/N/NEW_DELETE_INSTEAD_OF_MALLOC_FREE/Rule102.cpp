//@checker NEW_DELETE_INSTEAD_OF_MALLOC_FREE
typedef long size_t;
extern void* malloc (size_t size);

class C {
  int a;
};

struct S {
  int a;
};


void noncompliant() {
  C *p = (C*)malloc(sizeof(C)); //@violation NEW_DELETE_INSTEAD_OF_MALLOC_FREE
  S *q = (S*)malloc(sizeof(S)); //@violation NEW_DELETE_INSTEAD_OF_MALLOC_FREE
}


void compliant() {
  C *p = new C;
  S *q = new S;
}
