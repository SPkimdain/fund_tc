public class LoginView extends Frame           		 /* Safe */
        implements ActionListener, TextListener {    // @violation

    private Label lblTitle;
    private Label lblID;
}

    class LoginView2 extends Frame           	 // @violation
    implements ActionListener, TextListener {    // @violation
    }
    
   
class LoginView3 extends Frame			 		/* Safe */
    implements ActionListener, TextListener {  	/* Safe */
}

class LoginView4 extends Frame			 		/* Safe */
    implements ActionListener, TextListener,    /* Safe */
               ButtenListener {  	            /* Safe */
}

class LoginView5 extends Frame			 	    	/* Safe */
    implements ActionListener, TextListener,    /* Safe */
        ButtenListener, SoundListener,              // @violation
               OtherListener {  	                /* Safe */
}
