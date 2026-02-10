public class EmptyTryCatchTest {
    public static void main(String[] args) {
        try {
            throw new Exception();
        } catch (Exception e) {
            try {
                throw new Exception();
            } catch (Exception nestedE) { //@violation
                //test
            }
        }
    }
}
