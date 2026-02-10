// @checker FUNCTION_SHALL_BE_DECL_FILE_SCOPE

void FUNCSBDFS_001_function()
{
	int x;
	void FUNCSBDFS_001_function2(); // @violation FUNCTION_SHALL_BE_DECL_FILE_SCOPE
  
	int z = 0;
	if( z == 0 )	
	{
		void FUNCSBDFS_001_function3();  // @violation FUNCTION_SHALL_BE_DECL_FILE_SCOPE
	}
}
