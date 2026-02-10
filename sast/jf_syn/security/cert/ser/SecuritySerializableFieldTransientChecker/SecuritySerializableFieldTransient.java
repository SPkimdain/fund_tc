import java.io.Serializable;

public class Point {
    private double x;                   // @violation
    private double y;                   // @violation

    public Point(double x, double y) {
        this.x = x;
        this.y = y;
    }

    public Point() {
        // no-argument constructor
    }
}

public class Coordinates extends Point implements Serializable {
    public static void main(String[] args) {
        FileOutputStream fout = null;
        try {
            Point p = new Point(5, 2);
            fout = new FileOutputStream("point.ser");
            ObjectOutputStream oout = new ObjectOutputStream(fout);
            oout.writeObject(p);
        } catch (Throwable t) {
            // Forward to handler
        } finally {
            if (fout != null) {
                try {
                    fout.close();
                } catch (IOException x) {
                    // handle error
                }
            }
        }
    }
}


public class Point2 {
    private transient double x;                         /* Safe */
    private transient double y;                         /* Safe */

    public Point2(double x, double y) {
        this.x = x;
        this.y = y;
    }

    public Point2() {
        // no-argument constructor
    }
}

public class Coordinates2 extends Point2 implements Serializable {
    public static void main(String[] args) {
        FileOutputStream fout = null;
        try {
            Point2 p = new Point2(5,2);
            fout = new FileOutputStream("point.ser");
            ObjectOutputStream oout = new ObjectOutputStream(fout);
            oout.writeObject(p);
            oout.close();
        } catch (Exception e) {
            // Forward to handler
        } finally {
            if (fout != null) {
                try {
                    fout.close();
                } catch (IOException x) {
                    // handle error
                }
            }
        }
    }
}