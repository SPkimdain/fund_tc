// @checker BAD_INDENTATION.SWITCH_STATEMENT

#define TEST switch ( 1 ) { ; }

void nh_switch_2_4_2_9_7()
{
    switch ( 1 ) {
    }

    switch        // @violation BAD_INDENTATION.SWITCH_STATEMENT
	    ( 1 ) {
    }


    switch ( 1 )          // @violation BAD_INDENTATION.SWITCH_STATEMENT
    {
    }


    TEST                  // test false positive
}
