//@checker EXPR_NOT_BOOLEAN

void MISRA_5_0_14___f()
{
	int int_a = 1;
	int int_b = 1;
	int int_c = 1;
	int int_d = 1;
	bool bool_e = true;

	int_a = int_b ? int_c : int_d;         //Non-compliant  //@violation EXPR_NOT_BOOLEAN
	int_a = bool_e ? int_c : int_d;        //compliant
	int_a = (int_b < 5) ? int_c : int_d;   //compliant
}