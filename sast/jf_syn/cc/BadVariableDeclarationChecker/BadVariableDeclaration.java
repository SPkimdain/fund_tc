public class BadVariableDeclaration {

    private int a;
    private int b;
    private String strName;
    private String strName2;				// @violation
    private int c;
    private int g;
    private char onech;
    private char twoch;					/* Safe */
    private float d;
    private float f; 
    private Label ld;					/* Safe */
    
    void freeMethod() {
    	char onech;
        char twoch;					
        float d;
        float f;	 					/* Safe */
        Label ld;					
    }
    
    void freeMethod2() {
    	char onech;
        char twoch;					
        float d;
        float f;						// @violation
        char ld;					
    }
}
