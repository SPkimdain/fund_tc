package pmd;

public class ReturnFromFinallyBlock {
    public String test1() {
        try {
            throw new Exception("My Exception");
        } catch(Exception e) {
            throw e;
        } finally {
            return "BUG"; // @violation
        }
    }
}