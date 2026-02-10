// @checker DO_NOT_USE_FLOAT_AS_LOOP_COUNTERS



typedef float float32_t;
typedef double float64_t;

void DNUFLOATALC_001_funciton(char *p) {
	
	char *close;
	int temp = 0;
	char c = 0;
	int i = 0;
		
	float w, x, y, z;
	unsigned int mc2_1304_var1;
	unsigned int mc2_1304_var2;
	float mc2_1304_var3 = 0;
	float mc2_1304_var4;
	float mc2_1304_var5 [ 3 ] = { 1.0F, 2.0F, 3.0F };

	/* #1932 false alarm cases */
	for (close = p + 1; *close != '\0'; close++)
	{
	}

	for (temp = 2, c -= '0'; (temp & c) && temp--; i++)
	{
	}

	for (; temp < 100; i++)
	{

	}



    for ( w = 0.1f; w <= 1.0f; w += 0.1f) {  // @violation DO_NOT_USE_FLOAT_AS_LOOP_COUNTERS
	/* ... */
    }


    for ( x = 100000001.0f; x <= 100000010.0f; x += 1.0f) {  // @violation DO_NOT_USE_FLOAT_AS_LOOP_COUNTERS
	/* ... */
    }

	for ( y = 100.0f; y < 1000.0f; y++)	// @violation DO_NOT_USE_FLOAT_AS_LOOP_COUNTERS
	{
		/* ....*/
	}

	for ( z = 100; z < 10000; z++)// @violation DO_NOT_USE_FLOAT_AS_LOOP_COUNTERS
	{
	}

	
	for ( mc2_1304_var1 = 0U;    // @violation DO_NOT_USE_FLOAT_AS_LOOP_COUNTERS
		mc2_1304_var5 [ mc2_1304_var1 ] < mc2_1304_var3;
        mc2_1304_var1++ )
		{
		}
}


void DNUFLOATALC_001_funciton2() {
	register unsigned int n;
	unsigned count = 0;
	for (n = 0; n < 100; n++)
	{
		/*...*/
	}

  for (count = 1; count <= 10; count += 1) {
    float x = count/10.0f;
    /* ... */
  }



  for (count = 1; count <= 10; count += 1) {
    double x = 100000000.0 + count;
    /* ... */
  }
}
