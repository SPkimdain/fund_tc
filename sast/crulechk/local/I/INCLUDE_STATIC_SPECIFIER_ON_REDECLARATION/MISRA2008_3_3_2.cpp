//@checker INCLUDE_STATIC_SPECIFIER_ON_REDECLARATION

static void MISRA2008_3_3_2___f1();    //@b-violation INCLUDE_STATIC_SPECIFIER_ON_REDECLARATION
static void MISRA2008_3_3_2___f2();
void MISRA2008_3_3_2___f3();



void MISRA2008_3_3_2___f1() {}         //Non-compliant  //@violation INCLUDE_STATIC_SPECIFIER_ON_REDECLARATION
static void MISRA2008_3_3_2___f2() {}  //compliant
void MISRA2008_3_3_2___f3(){}          //compliant 


