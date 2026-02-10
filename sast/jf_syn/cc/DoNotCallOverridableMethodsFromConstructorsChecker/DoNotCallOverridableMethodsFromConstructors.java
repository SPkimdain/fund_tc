public class Test {
    public SuperClass() {
        doLogic(); //@violation
    }

    public void doLogic() {
        System.out.println("This is superclass!");
    }
}