//@checker FUNCTION_WITH_VOID_RETURN_TYPE_SHOULD_HAVE_EXTERNAL_SIDE_EFFECT

int globalNum;
int globalNum2;
void FWVRTSHESE_003_function8()  //compliant
{
  globalNum += 5;
  globalNum2 = 3;

  int localNum;
  localNum = 6;
}



void FWVRTSHESE_003_function9()  //@violation FUNCTION_WITH_VOID_RETURN_TYPE_SHOULD_HAVE_EXTERNAL_SIDE_EFFECT
{

}

void FWVRTSHESE_003_function10() //compliant
{
  FWVRTSHESE_003_function9();
}


void FWVRTSHESE_003_function11() //compliant
{
  volatile int num;

  int iNum = 0;

  volatile int* pNum;

  int iNum2 = 0;

  volatile int &ref = iNum;

  volatile double dNum;

  int *pNum2;
}



