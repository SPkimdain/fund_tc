import java.io.Externalizable;
import java.io.ObjectInput;
import java.io.ObjectOutput;

public class SecurityImplementExternalizable1 implements Externalizable {
    public void readExternal(ObjectInput in)
            throws IOException, ClassNotFoundException {
        // Read instance fields
        this.name = (String) in.readObject();                       // @violation
        this.UID = in.readInt();                                    // @violation
        //...
    }
}

public class SecurityImplementExternalizable2 implements Externalizable {
    private final Object lock = new Object();
    private boolean initialized = false;

    public void readExternal(ObjectInput in)
            throws IOException, ClassNotFoundException {
        this.name = (String) in.readObject();                       // @violation
        synchronized (lock) {
            this.name = (String) in.readObject();                   // @violation
            if (!initialized) {
                // Read instance fields
                this.name = (String) in.readObject();               /* Safe */
                this.UID = in.readInt();                            /* Safe */
                //...
                initialized = true;
            } else {
                throw new IllegalStateException();
            }
        }
    }

    public void writeExternal(ObjectOutput out)
            throws IOException, ClassNotFoundException {
        ClassTest2 test2;
        test2.method2().method1().write();                          // @violation
        synchronized (lock) {
            out.writeObject();                                      // @violation
            if (!initialized) {
                // Write
                out.writeObject();                                  /* Safe */
                out.writeChar();                                    /* Safe */
                //...
                initialized = true;
            } else {
                throw new IllegalStateException();
            }
        }
    }
}

public class ClassTest {
    public ObjectOutput method1() {
        ObjectOutput out;
        return out;
    }
}

public class ClassTest2{
    public ClassTest method2() {
        ClassTest test;
        return test;
    }
}