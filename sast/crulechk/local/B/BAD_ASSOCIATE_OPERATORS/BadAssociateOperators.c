// @checker BAD_ASSOCIATE_OPERATORS
 
void foo (void) {
	int a = 2;
	int b = 2;
	int c = 2;

	if( (a < b) > c)	//@violation	BAD_ASSOCIATE_OPERATORS
	{
	}

	if( (a == b) == c){ //@violation	BAD_ASSOCIATE_OPERATORS
	}

	/* ... */
	if (a < b < c){ //@violation	BAD_ASSOCIATE_OPERATORS
	/* ... */
	}
	if (a == b == c){	//@violation	BAD_ASSOCIATE_OPERATORS
	}

	

	
	if ( (a < b) && (b < c) ) {/* clearer, and probably what was intended */
	}
/* ... */
	if ( (a == b) && (a == c) ) {/* ditto */
	}
}

