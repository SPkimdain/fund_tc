package src.test.java.pmd;

public class AvoidCatchingGenericException {
    public void downCastPrimitiveType() {
        try {
            System.out.println(" ");
        } catch(Exception e) { // @violation
            e.printStackTrace();
        } catch(RuntimeException e) { // @violation
            e.printStackTrace();
        } catch(NullPointerException e) { // @violation
            e.printStackTrace();
        }
    }
}