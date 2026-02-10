// @checker DO_NOT_RECURSIVELY_REENTER_DURING_INIT_STATIC

int noncompliant (int x) {
    x--;
    if (x < 0 || x > 10) {
	return 0;
    }
    else {
	static int y = noncompliant(x);  // @violation DO_NOT_RECURSIVELY_REENTER_DURING_INIT_STATIC
	return y;
    }
}



int compliant (int x) {
    x--;
    if (x < 0 || x > 10) {
	return 0;
    }
    else {
	static int y;
	y = compliant(x);
	return y;
    }
}
