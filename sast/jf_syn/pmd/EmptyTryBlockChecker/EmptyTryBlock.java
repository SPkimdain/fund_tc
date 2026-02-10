package src.test.java.pmd;

public class EmptyTryBlock {
    void test1() {
        try { // @violation
            ;;;
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    void test2() {
        try(BufferedReader br = new BufferedReader(new FileReader(path))) { /* OK */
            ;
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}