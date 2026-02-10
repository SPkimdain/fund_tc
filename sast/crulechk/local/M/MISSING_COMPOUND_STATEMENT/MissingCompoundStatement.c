// @checker MISSING_COMPOUND_STATEMENT

void foo()
{
    for (;;) {}
    while (1)
    {}

    for (;;)
	;             // @violation MISSING_COMPOUND_STATEMENT
    while (1) ;       // @violation MISSING_COMPOUND_STATEMENT
}
