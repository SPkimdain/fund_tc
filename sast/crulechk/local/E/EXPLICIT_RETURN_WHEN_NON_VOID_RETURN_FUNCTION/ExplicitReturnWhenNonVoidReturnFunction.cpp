
//@checker EXPLICIT_RETURN_WHEN_NON_VOID_RETURN_FUNCTION

int ERWNVRF(int a) //@violation EXPLICIT_RETURN_WHEN_NON_VOID_RETURN_FUNCTION
{
  a = a+1;
}


int ERWNVRF_TN(int a)
{
  a = a+1;
  return a;
}
