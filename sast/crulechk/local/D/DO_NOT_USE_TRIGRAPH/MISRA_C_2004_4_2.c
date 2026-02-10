// @checker DO_NOT_USE_TRIGRAPH

#include <stdio.h>

void func(void) {
    printf("I am hungry. Please help me.");
    printf("what??!"); // @violation DO_NOT_USE_TRIGRAPH
    printf("Date will be in the form ??-??-??"); // @violation DO_NOT_USE_TRIGRAPH
}
