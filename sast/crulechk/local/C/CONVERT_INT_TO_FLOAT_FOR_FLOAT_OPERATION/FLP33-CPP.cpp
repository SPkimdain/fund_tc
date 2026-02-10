// @checker CONVERT_INT_TO_FLOAT_FOR_FLOAT_OPERATION

void noncompliant () {
    short a = 533;
    int b = 6789;
    long c = 466438237;

    float d = a / 7; /* d is 76.0 */    // @violation CONVERT_INT_TO_FLOAT_FOR_FLOAT_OPERATION
    double e = b / 30; /* e is 226.0 */   // @violation CONVERT_INT_TO_FLOAT_FOR_FLOAT_OPERATION
    double f = c * 789; /*  f may be negative due to overflow */    // @violation CONVERT_INT_TO_FLOAT_FOR_FLOAT_OPERATION
}



void compliant() {
    short a = 533;
    int b = 6789;
    long c = 466438237;

    float d = a / 7.0f; /* d is 76.14286 */
    double e = b / 30.; /* e is 226.3 */
    double f = (double)c * 789; /* f is 368019768993.0 */
}


void compliant2() {

    short a = 533;
    int b = 6789;
    long c = 466438237;

    float d = a;
    double e = b;
    double f = c;

    d /= 7; /* d is 76.14286 */
    e /= 30; /* e is 226.3 */
    f *= 789; /* f is 368019768993.0 */
}
