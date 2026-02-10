// @checker SIZEOF_DO_NOT_CONTAIN_SIDE_EFFECTS

void SIZEOFDNCSE_001_function()
{
	int i;
	int i_size;
	int a = 14;
	int b;

	int j_size = sizeof(int);
	

	b = sizeof(a++);	// @violation SIZEOF_DO_NOT_CONTAIN_SIDE_EFFECTS
	i_size = sizeof(i = 3000);	// @violation SIZEOF_DO_NOT_CONTAIN_SIDE_EFFECTS
	i_size = sizeof(i);
		
	b = sizeof(int [a % 1 + 1]);	

}
