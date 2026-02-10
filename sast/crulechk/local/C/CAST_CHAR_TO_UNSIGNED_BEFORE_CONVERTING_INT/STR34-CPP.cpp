// @checker CAST_CHAR_TO_UNSIGNED_BEFORE_CONVERTING_INT

static int noncompliant_yy_string_get(char** input) {
    register char *string;
    register int c;

    string = *input;
    c = '\0';

    /* If the string doesn't exist, or is empty, EOF found. */
    if (string && *string) {
	c = *string++;    // @violation CAST_CHAR_TO_UNSIGNED_BEFORE_CONVERTING_INT
	*input = string;
    }
    return (c);
}



static int semi_compliant_yy_string_get(unsigned char** input) {
    register unsigned char *string;
    register int c;

    string = *input;
    c = '\0';

    /* If the string doesn't exist, or is empty, EOF found. */
    if (string && *string) {
	c = *string++;
	*input = string;
    }
    return (c);
}




static int compliant_yy_string_get(char** input) {
    register char *string;
    register int c;

    string = *input;
    c = '\0';

    /* If the string doesn't exist, or is empty, EOF found. */
    if (string && *string) {
	/* cast to unsigned type */
	c = (unsigned char)*string++;

	*input = string;
    }
    return (c);
}
