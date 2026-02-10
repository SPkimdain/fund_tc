
/* UASGN_001 - simple case */

void UASGN_001_function() {
    int a = 2;
    int b = 0;
    
    b = a + 2; //b is 4.
    //a is already 2.
    b = b - 2;
    a = b; //@violation USELESS_ASSIGNMENT    
}

