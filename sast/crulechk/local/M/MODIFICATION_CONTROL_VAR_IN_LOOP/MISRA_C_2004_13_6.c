// @checker MODIFICATION_CONTROL_VAR_IN_LOOP


// from #1935
void foo()
{
	for(;;){
		char *close, *ccname;
		char *p = 0;    /* make sure invalid char classes don't match. */
		for (close = p + 1; *close != '\0'; close++)
		{
			if (*close == ':' && *(close+1) == ']'){
				break;
			}
		}
	}
}

void func()
{
	int a = 0;
	
	for(a = 0; a < 10; a++)
	{
		a++;	// @violation MODIFICATION_CONTROL_VAR_IN_LOOP
		a = 8;	// @violation MODIFICATION_CONTROL_VAR_IN_LOOP
		int b = a++;	// @violation MODIFICATION_CONTROL_VAR_IN_LOOP
		for(b = 0; b < 5; b++)
		{
			a--;	// @violation MODIFICATION_CONTROL_VAR_IN_LOOP
			b++;	// @violation MODIFICATION_CONTROL_VAR_IN_LOOP
		}
	}
}

