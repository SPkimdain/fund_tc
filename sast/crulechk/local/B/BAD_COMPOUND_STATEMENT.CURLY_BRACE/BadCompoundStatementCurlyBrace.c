// @checker BAD_COMPOUND_STATEMENT.CURLY_BRACE

void nh_2_4_2_9_2_2(int a)
{
    int count = 0;

    if ( a ) {
        count++;
    } else {
        count--;
    }

    if ( a ) { count++; }  // @violation BAD_COMPOUND_STATEMENT.CURLY_BRACE
    else {
        count--;
         }                 // @violation BAD_COMPOUND_STATEMENT.CURLY_BRACE
}
