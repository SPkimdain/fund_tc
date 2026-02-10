public class OuterSer implements Serializable {
    private int rank;
    class InnerSer implements Serializable {    // @violation
        protected String name;
        //...
    }
}


public class OuterSer implements Serializable {
    private int rank;
    class InnerSer {                            /* Safe */
        protected String name;
        //...
    }
}


public class OuterSer implements Serializable {
    private int rank;
    static class InnerSer implements Serializable {     /* Safe */
        protected String name;
        //...
    }
}