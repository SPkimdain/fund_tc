// @checker CATCH_EXCEPTIONS_BY_REFERENCE

class exception {
};

void foo()
{
    int a;
    try {
	a = 1;
    }
    catch ( exception &e ) {
	a = 0;
    }

    try {
	a = 1;
    }
    catch ( exception* e ) {  // @violation CATCH_EXCEPTIONS_BY_REFERENCE
	a = 0;
    }
}
