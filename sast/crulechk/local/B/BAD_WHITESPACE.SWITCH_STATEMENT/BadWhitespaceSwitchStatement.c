// @checker BAD_WHITESPACE.SWITCH_STATEMENT


#define SWITCH switch (n) {}

void nh_2_4_2_9_7_2( int n )
{
    switch ( n ) {}
    switch (n ) {}     // @violation BAD_WHITESPACE.SWITCH_STATEMENT
    switch ( n) {}     // @violation BAD_WHITESPACE.SWITCH_STATEMENT

    SWITCH
}
