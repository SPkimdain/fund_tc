class foo {
    int a;
    private String b;
    public foo() {
    							// @violation
    }
    void make() {
    	int c;					// @violation
    		String d;      		// @violation
    }
}