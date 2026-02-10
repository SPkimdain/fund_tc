class Base {
    static DateFormat format =
            DateFormat.getDateInstance(DateFormat.MEDIUM);

    public Date parse(String str) throws ParseException {
        synchronized (getClass()) {                             // @violation
            return format.parse(str);
        }
    }
}

class Base2 {
    static DateFormat format =
            DateFormat.getDateInstance(DateFormat.MEDIUM);

    public Date parse(String str) throws ParseException {
        synchronized (getClass()) {                             // @violation
            return format.parse(str);
        }
    }

    public Date doSomething(String str) throws ParseException {
        return new Helper().doSomethingAndParse(str);
    }

    private class Helper {
        public Date doSomethingAndParse(String str) throws ParseException {
            synchronized (Helper.getClass()) {                         // @violation
                // ...
                return format.parse(str);
            }
        }
    }
}

class Base3 {
    // ...

    public Date parse(String str) throws ParseException {
        synchronized (Base3.class) {                                /* Safe */
            return format.parse(str);
        }
    }

    private class Helper {
        public Date doSomethingAndParse(String str) throws ParseException {
            synchronized (Base3.class) {                            /* Safe */
                // ...
                return format.parse(str);
            }
        }
    }
}