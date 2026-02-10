package cc;

public class ReturnInCatchStatement {
    public static final boolean doStuff1() {
        boolean threadLock;
        boolean truthvalue = true;
        try {
            while (condition) {
                threadLock = true; //do some stuff to truthvalue
                threadLock = false;
            }
        } catch (Exception e) {
            System.err.println("You did something bad");
            if (something) return truthvalue;   // @violation
        }
        return truthvalue;
    }

    public static final boolean doStuff2( ) {
        boolean threadLock;
        boolean truthvalue=true;
        try {
            while(condition) {
                threadLock=true; //do some stuff to truthvalue
                threadLock=false;
            }
        }
        catch (Exception e){
            System.err.println("You did something bad");
            //if (something) return truthvalue;
        }
        return truthvalue;
    }
}