//@checker WRITE_VIRTUAL_DTOR_FOR_BASE_CLASS

#include "3_3_2.h"

Base2::~Base2()
{
}//@violation WRITE_VIRTUAL_DTOR_FOR_BASE_CLASS

void WVDTORFBC_001_function()
{
	TDerived2 td2;
}
