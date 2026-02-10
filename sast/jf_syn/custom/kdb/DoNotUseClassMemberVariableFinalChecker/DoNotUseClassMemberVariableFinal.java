public class ForbiddenFieldUsage {

    private final int testcounter; //@violation

    public void increment() {

        counter++;
        int yes = 0;

        System.out.println(yes);


    }
}