//@checker UNREACHABLE_CODE
void UR_003_function() {

    int a = 1;

    while(a > 2 || a == 0) {  //@violation UNREACHABLE_CODE
        a = 4; 
    }

    a = 0;

}