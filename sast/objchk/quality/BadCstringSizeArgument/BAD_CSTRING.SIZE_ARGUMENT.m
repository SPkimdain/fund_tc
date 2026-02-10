void test() {
  char dest[3];
  char dest2[3];
  strncat(dest, "***", sizeof(dest));//@violation
  strncat(dest2, "***", sizeof(int));//@violation
    //potential buffer overflow
}
