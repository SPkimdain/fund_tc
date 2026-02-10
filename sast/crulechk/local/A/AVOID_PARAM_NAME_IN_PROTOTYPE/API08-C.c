//@checker AVOID_PARAM_NAME_IN_PROTOTYPE
void foo(int a);	//@violation AVOID_PARAM_NAME_IN_PROTOTYPE
void bar(int a);	//@violation AVOID_PARAM_NAME_IN_PROTOTYPE

void bar(int a) {
  int b = 0;
}


void zoo(int);

void zoo(int a) {
  int b = 0;
}
