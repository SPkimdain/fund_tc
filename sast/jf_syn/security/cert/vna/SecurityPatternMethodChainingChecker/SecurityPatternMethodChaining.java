class SecurityPatternMethodChaining {
    private int quarters = 0;
    private int dimes = 0;
    private int nickels = 0;
    private int pennies = 0;

    private final ExampleClientCode currency = new ExampleClientCode();
    private volatile ExampleClientCode currency2 = new ExampleClientCode();

    public ExampleClientCode() {

        Thread t1 = new Thread(new Runnable() {
            @Override public void run() {
                currency.setQuarters(1).setDimes(1);        // @violation
                currency2 = ExampleClientCode.setQuarters(1).setDimes(1).build();
            }
        });
        t1.start();

        Thread t2 = new Thread(new Runnable() {
            @Override public void run() {
                currency.setQuarters(2).setDimes(2);        // @violation
                currency2 = ExampleClientCode.setQuarters(2).setDimes(2).build();
            }
        });
        t2.start();

        //...
    }

    public ExampleClientCode setQuarters(int quantity) {
        this.quarters = quantity;
        return this;
    }
    public ExampleClientCode setDimes(int quantity) {
        this.dimes = quantity;
        return this;
    }
    public ExampleClientCode setNickels(int quantity) {
        this.nickels = quantity;
        return this;
    }
    public ExampleClientCode setPennies(int quantity) {
        this.pennies = quantity;
        return this;
    }
}