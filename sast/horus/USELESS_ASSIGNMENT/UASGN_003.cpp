
/* UASGN_003 - pointer null */
void UASGN_002_function(int* out, int flag) {
    int* ptr = 0;
    
    int* ptr2 = out;

    if(flag > 10) {
        ptr2 = 0;
    }
    /* ptr2 is already nullptr when flag <= 10 */
    ptr2 = ptr; //@violation USELESS_ASSIGNMENT    
}

