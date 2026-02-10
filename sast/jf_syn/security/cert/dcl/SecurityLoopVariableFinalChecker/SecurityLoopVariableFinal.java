public class SecurityLoopVariableFinal {
    public void getTest() {
        for(String str : list) {        // @violation

        }
    }
}