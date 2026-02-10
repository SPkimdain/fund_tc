public class ForbiddenFieldUsage {

    private int testcounter; //@violation

    public void increment() {

        counter++;
        int yes = 0;

        System.out.println(yes);


    }
}