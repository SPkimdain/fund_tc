//@checker FORBIDDEN.MODIFY_PARAMETER

typedef int int16_t;

int16_t glob = 0;

void proc (int16_t para)
{
  para = glob; //@violation	 FORBIDDEN.MODIFY_PARAMETER
}

void f (char* p, char* q)
{
  p = q; //@violation	 FORBIDDEN.MODIFY_PARAMETER
 *p = *q; /* compliant */
}
