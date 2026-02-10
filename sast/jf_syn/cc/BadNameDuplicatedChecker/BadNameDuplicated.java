package cc;

import java.lang.String;

public class BadNameDuplicated {
    public String name;
    public String name() { // @violation
        return name;
    }

    class MyClass {
        public MyClass() {}
        public void MyClass() { // @violation
            // Do something
        }
    }
}
