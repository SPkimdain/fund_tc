//@checker BAD_CAST_COMPLEX_EXPR

void BCCE_18959()
{
	float tempCalRx = 0.0f;
	int i = 5;
	float fi = 5;
	tempCalRx = (float)(((float)i*125.0f)+7125000.0f)/1000.0f; // @violation BAD_CAST_COMPLEX_EXPR
	tempCalRx = (float)(((float)fi*125.0f)+7125000.0f)/1000.0f; 
}