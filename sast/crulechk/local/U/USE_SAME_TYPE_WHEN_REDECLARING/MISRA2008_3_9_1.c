//@checker USE_SAME_TYPE_WHEN_REDECLARING

typedef int INT;
INT MISRA2008_3_9_1___i;
extern int MISRA2008_3_9_1___i;      //Non-compliant   //@violation USE_SAME_TYPE_WHEN_REDECLARING

INT MISRA2008_3_9_1___j;
extern INT MISRA2008_3_9_1___j;      //compliant


extern void MISRA2008_3_9_1___f(signed int);
void MISRA2008_3_9_1___f(int);                 //Non-compliant   //@violation USE_SAME_TYPE_WHEN_REDECLARING


extern void MISRA2008_3_9_1___g(const int);
void MISRA2008_3_9_1___g(int);                 //Non-compliant   //@violation USE_SAME_TYPE_WHEN_REDECLARING





//추가 예제
extern void MISRA2008_3_9_1___g(const int, int);
void MISRA2008_3_9_1___g(int, int);                       //Non-compliant   //@violation USE_SAME_TYPE_WHEN_REDECLARING
void MISRA2008_3_9_1___g(int, signed int);                //Non-compliant   //@violation USE_SAME_TYPE_WHEN_REDECLARING
void MISRA2008_3_9_1___g(const int, int);                 //compliant

extern void MISRA2008_3_9_1___g(int, int, int);
void MISRA2008_3_9_1___g(int, int, int);                  //compliant
