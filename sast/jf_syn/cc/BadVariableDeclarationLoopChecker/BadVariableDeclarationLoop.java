class foo {

	public void loopTest() {
		int j;
		for(int counter =0; counter < 3; counter++) {} 	/* Safe */
		for(j = 0; j < 3; j++) {} 						// @violation
		for(int i = 0; i < 3; i++) {}					// @violation /* if check_declaration_in_loop is true, would be Bug */
	}
}