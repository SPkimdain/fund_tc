//@checker USE_ONE_STATEMENT_PER_LINE

#define DUP(a, b) a= b; a =b;

void func()
{
   int a; int b;        //@violation USE_ONE_STATEMENT_PER_LINE

   DUP(a, b)
}
