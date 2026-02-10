public final class MutableClass {
    private Date date;

    public MutableClass(Date d) {
        this.date = d;
    }

    public void setDate(Date d) {
        this.date = d;
    }

    public Date getDate() {
        return date;            // @violation
    }
}


public final class MutableClass2 { // Copy Constructor
    private final Date date;

    public MutableClass(MutableClass mc)  {
        this.date = new Date(mc.date.getTime());            /* Safe */
    }

    public MutableClass(Date d) {
        this.date = new Date(d.getTime());  // Make defensive copy
    }

    public Date getDate() {
        return (Date) date.clone(); // Copy and return
    }
}