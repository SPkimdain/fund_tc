class Super {
    protected void doLogic() {                  // @violation
        System.out.println("Super invoked");
    }

    protected final void doLogicExam() {                  /* Safe */
        System.out.println("Super invoked");
    }
}

public class Sub extends Super {
    public void doLogic() {
        System.out.println("Sub invoked");
        // Do sensitive operations
    }
}