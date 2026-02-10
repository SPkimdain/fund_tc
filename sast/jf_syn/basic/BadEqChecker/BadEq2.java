package test.com.fasoo.javafinch.syn.rule.basic.badeq;

/**
 * BAD_EQ Test case 2 : BAD_EQ - Ignore null comparison
 * Null 비교를 무시하는지 확인
 * @author JWYoon
 *
 */
public class BadEq2 {

    class OverrideEquals {
        public String name;

        public boolean equals(Object o) {
            OverrideEquals other = (OverrideEquals)o;
            return(other.name.equals(this.name));
        }
    }

    class StructuralMajor {
        OverrideEquals objA = null;
        OverrideEquals objB = null;

        public void method() {
            if(objA == objB) {}
            if(objA.equals(objB)) {}
            if(objA.equals(objB)) {}
            if(objA.equals(objB)) {}
            if(objA.equals(null)) {}
        }
    }

    class ReferentialMajor {
        OverrideEquals objA = null;
        OverrideEquals objB = null;

        public void method() {
            if(objA == objB) {}
            if(objA == objB) {}
            if(objA == objB) {}
            if(objA == null) {}
            if(objA.equals (objB)) {}
        }
    }
}