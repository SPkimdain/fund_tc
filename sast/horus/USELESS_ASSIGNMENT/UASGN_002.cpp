
/* UASGN_002 - pointer null */
void UASGN_002_function(int* out) {
    int* ptr = 0;
    
    int* ptr2 = out;

    ptr2 = 0;
    /* ptr2 is already nullptr. */
    ptr2 = ptr; //@violation USELESS_ASSIGNMENT    
}

