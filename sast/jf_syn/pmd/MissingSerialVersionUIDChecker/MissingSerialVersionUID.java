package pmd;

import java.io.Serializable;

public class MissingSerialVersionUID implements Serializable { // @violation
    String name;
    // no serialVersionUID error

    class TestCase1 implements Serializable { /* safe */
        long serialVersionUID = 1L;
    }

    class TestCase2 implements Serializable { // @violation
        String name1;
        // no serialVersionUID error
    }

    class TestCase3 implements java.io.Serializable { // @violation
        String name2;
    }
}