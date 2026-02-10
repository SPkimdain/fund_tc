package pmd;

class Parent {
    Parent() { // @violation
        fun1();
        fun2("a");
    }

    public String fun1() {
        return "parent";
    }

    public String fun2(String a) {
        return "parent";
    }
}

public class ConstructorCallsOverridableMethod extends Parent {

    public ConstructorCallsOverridableMethod() {
        super();
    }

    public String fun1() {
        return "children";
    }

    public String fun2(String a) {
        return "children";
    }
}