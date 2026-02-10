import java.io.Serializable;

public class SensitiveClass extends Number {                            // @violation
    // ..implement abstract methods, such as Number.doubleValue()â¦

    private static final SensitiveClass INSTANCE = new SensitiveClass();
    public static SensitiveClass getInstance() {
        return INSTANCE;
    }

    private SensitiveClass() {
        // Perform security checks and parameter validation
    }

    private int balance = 1000;
    protected int getBalance() {
        return balance;
    }
}

class Number implements Serializable {
    // ..
}

public class SensitiveClass3 extends Number3 {                            // @violation
    // ...

    private final Object writeObject(java.io.ObjectOutputStream out) throws NotSerializableException {
        throw new NotSerializableException();
    }
    private final Object readObject(java.io.ObjectInputStream in) throws NotSerializableException {
        throw new NotSerializableException();
    }
}

class Number3 implements Serializable {
    // ..
}