// @checker BAD_WHITESPACE.IF_STATEMENT

void nh_2_4_2_9_6_1( )
{
    if ( 1 ) {}
    if ( 1) {}        // @violation BAD_WHITESPACE.IF_STATEMENT
    if (1 ) {}        // @violation BAD_WHITESPACE.IF_STATEMENT
    if (1             // @violation BAD_WHITESPACE.IF_STATEMENT
	) {}
    if (
	    1) {}     // @violation BAD_WHITESPACE.IF_STATEMENT
    if (
	    1
	)
    {
    }

}
