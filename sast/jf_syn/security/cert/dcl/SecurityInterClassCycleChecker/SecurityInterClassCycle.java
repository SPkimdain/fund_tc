package cert.dcl;

class A {
    public static final int a = B.b + 1;    // @violation
}

class B {
    public static final int b = C.c + 1;    // @violation
    // ...
}

class C {
    public static final int c = A.a + 1;    // @violation
    // ...
}