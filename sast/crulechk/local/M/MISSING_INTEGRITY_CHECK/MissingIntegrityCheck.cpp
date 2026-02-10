//@checker MISSING_INTEGRITY_CHECK

bool InternetReadFile();

int func( )
{
	bool rv1;
	rv1 = InternetReadFile();
	InternetReadFile();	//@violation MISSING_INTEGRITY_CHECK

	bool rv = InternetReadFile();
	if(rv)
	{
		//.....
	}

	if(InternetReadFile() == true)
	{
		// ....
	}

  return 0;
}
