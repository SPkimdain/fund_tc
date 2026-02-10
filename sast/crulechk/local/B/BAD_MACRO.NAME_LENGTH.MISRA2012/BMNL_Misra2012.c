//@checker BAD_MACRO.NAME_LENGTH.MISRA2012
#define test_macro_name_test_macro_name_test_macro_name_test_macro_name_test_macro_name char	//@violation BAD_MACRO.NAME_LENGTH.MISRA2012
#define test_macro_name_test_macro_name_test_macro_name_test char
void BMNL_Misra2012() 
{
	int a = 0;
}