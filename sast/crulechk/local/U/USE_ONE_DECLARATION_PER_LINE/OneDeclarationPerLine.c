// @checker USE_ONE_DECLARATION_PER_LINE

int a;
int b; int c;  // @violation USE_ONE_DECLARATION_PER_LINE
int d, e;     // @violation USE_ONE_DECLARATION_PER_LINE



void foo() {
  int a;
  int b; int c;         // @violation USE_ONE_DECLARATION_PER_LINE
  static int d; int e;  // @violation USE_ONE_DECLARATION_PER_LINE
  int f, g;             // @violation USE_ONE_DECLARATION_PER_LINE
}
