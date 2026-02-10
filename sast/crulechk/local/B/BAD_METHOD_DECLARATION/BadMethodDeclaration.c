// @checker BAD_METHOD_DECLARATION


//2.4.2.7.4
void foo() {}

void bar(void) {}   // @violation BAD_METHOD_DECLARATION


void foo1();
void foo2(void );   // @violation BAD_METHOD_DECLARATION



void nh_2_4_2_7_5(
    int a,
    int b, int c,
    int d,int e   // @violation BAD_METHOD_DECLARATION
                 );



void nh_2_4_2_7_6( int a,
                   int b, int c,
                   int d,
            int e     // @violation BAD_METHOD_DECLARATION
                   )
{
}
