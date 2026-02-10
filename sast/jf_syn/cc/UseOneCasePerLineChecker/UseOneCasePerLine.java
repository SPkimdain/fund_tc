class foo {
	public void foo() {
		switch(1) {
			case 1: case 2: 	// @violation
			a=1;
			break;
			case 3: 			/* Safe */
			default:
		}
		
		switch(2) {
			case 1: 			/* Safe */
			a=1;
			break;
			case 2: default:	// @violation
				break;
		}
	}

}