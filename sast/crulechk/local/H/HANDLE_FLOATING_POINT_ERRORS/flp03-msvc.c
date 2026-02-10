//@checker HANDLE_FLOATING_POINT_ERRORS

void HNDLFPE_001_function()
{
	double a = 1e-40, b, c = 0.1;
	float x = 0, y;
	
	/* Inexact and underflows */
	y = a; //@violation HANDLE_FLOATING_POINT_ERRORS
	
	/* Divide-by-zero operation */
	b = y / x; //@violation HANDLE_FLOATING_POINT_ERRORS
	
}
