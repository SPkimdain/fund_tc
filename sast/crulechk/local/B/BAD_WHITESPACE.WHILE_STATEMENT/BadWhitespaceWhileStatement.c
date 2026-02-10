// @checker BAD_WHITESPACE.WHILE_STATEMENT

#define WHILE while (0) {}
#define DOWHILE do {} while (0)

void nh_2_4_2_9_4_1( )
{
    while ( 0 ) {}
    while ( 0) {}         // @violation BAD_WHITESPACE.WHILE_STATEMENT
    while (0 ) {}         // @violation BAD_WHITESPACE.WHILE_STATEMENT
    while (
	       0) {}         // @violation BAD_WHITESPACE.WHILE_STATEMENT
    while (0                // @violation BAD_WHITESPACE.WHILE_STATEMENT
	   ) {}
    while (
	       0)        // @violation BAD_WHITESPACE.WHILE_STATEMENT
    {
    }

    WHILE
}


void nh_2_4_2_9_5_3( )
{
    do {}
    while ( 0 );
    do {}
    while ( 0);         // @violation BAD_WHITESPACE.WHILE_STATEMENT
    do {}
    while (0 );         // @violation BAD_WHITESPACE.WHILE_STATEMENT

    DOWHILE;
}
