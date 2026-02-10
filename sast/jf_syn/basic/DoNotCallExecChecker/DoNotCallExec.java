package basic;

public class DoNotCallExec {
    Runtime runtime = Runtime.getRuntime();

    public void func(String commeand) {
        runtime.exec(command); // @violation
    }
    public void func2(String commeand) {
        Runtime.getRuntime().exec(command); // @violation
    }
    public void lambdaFunc(String command) {
        Runtime runtime = Runtime.getRuntime();

        Consumer<String> consumer = s -> {
            runtime.exec(s); // @violation
        };
        consumer.accept(command);
    }

    public void lambdaFunc1(String command) {
        Consumer<String> consumer = s -> {
            Runtime runtime = Runtime.getRuntime();
            runtime.exec(s); // @violation
        };
        consumer.accept(command);
    }
    public void lambdaFunc2(String command) {
        Consumer<String> consumer = s -> Runtime.getRuntime().exec(s); // @violation
        consumer.accept(command);
    }
}