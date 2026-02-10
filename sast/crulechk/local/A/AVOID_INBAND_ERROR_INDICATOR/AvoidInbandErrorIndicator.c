// @checker AVOID_INBAND_ERROR_INDICATOR

extern int sprintf(char* str, const char* format, ...);

void foo()
{
	int i;
	int count = 0;
	char buf[100] = "";
	unsigned char* slreg_num[100];
	 
	for (i = 0; i < 9; ++i) {
	  count += sprintf(buf + count, "%02x ", ((unsigned char *)&slreg_num)[i] );	// @violation AVOID_INBAND_ERROR_INDICATOR
	}
	count += sprintf(buf + count, "\n");	// @violation AVOID_INBAND_ERROR_INDICATOR
}

