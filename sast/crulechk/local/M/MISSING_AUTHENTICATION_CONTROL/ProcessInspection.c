// @checker MISSING_AUTHENTICATION_CONTROL

extern inspect();


void manager() {
  inspect();
}


void manager2() { // @violation MISSING_AUTHENTICATION_CONTROL
  int a = 0;
}

void foo() {
  inspect();
}
