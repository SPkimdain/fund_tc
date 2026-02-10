// @checker DO_NOT_SPECIFY_BOUND_OF_ARRAY_FOR_STRING_LITERAL


void noncompliant () {
    // const char s[3] = "abc";   // compiler error
    const char s2[4] = "abc";  // @violation DO_NOT_SPECIFY_BOUND_OF_ARRAY_FOR_STRING_LITERAL
}

void compliant () {
    const char s[] = "abc"; //It's ok.
    char s2[3] = { 'a', 'b', 'c' };  //It's ok.
}
