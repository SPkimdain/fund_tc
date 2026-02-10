/**
 * An allowed indentation number is 4. 
 * An allowed blank number is 1 in between cases. 
 * @author Byungho
 *
 */


class foo {
public void make() {
	switch(1) {
	    case 1:			/* Safe */
	        a=2;
	        break;

	case 2: 			// @violation
	    b=2;
	    break;
	             
	        default : 	// @violation
	            break;
	}
	
	switch(1) {
	    case 1:			/* Safe */
	        a=2;
	        break;
	    case 2:			// @violation
	        b=3;
	        break;
	   
	 /*  */ break;
	    case 3:			// @violation
	        c=4;
	        break;
	   
	    default:		/* Safe */
	        break;
	}
	
	switch(1) {
	    case 1:
	        a=2;			/* Safe */
	        break;			/* Safe */
	    
	    case 2:
	    	    b=3;   		// @violation
	    	    break;		// @violation
	    
	    case 3:
	    c=4;				// @violation
	    break;				// @violation
	    
	    default:			/* Safe */
	        break;			/* Safe */
	    		
	}

    // False alarm case from NH : 20140620
    int hashCode = fieldName.hashCode();
    switch(hashCode) {
        case 514137987: return new AbstractDataObjectList(this.lACO1010R0_Session_OUT);

        default: throw new ProframeException("unknown fieldName : " + fieldName);
    }
}
}
