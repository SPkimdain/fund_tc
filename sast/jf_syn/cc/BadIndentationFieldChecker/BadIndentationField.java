public class LoginView {
    private Label lblTitle;		/* Safe */
    private Label lblID;		/* Safe */
}

class LoginView2 {  
private Label lblTitle;		// @violation
private Label lblID;		// @violation
	
}
    
   
class LoginView3 {			
    private Label lblTitle;		/* Safe */
        private Label lblID;		// @violation
}

