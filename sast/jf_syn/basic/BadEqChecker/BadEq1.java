package test.com.fasoo.javafinch.syn.rule.basic.badeq;

/**
 * BAD_EQ Test case 1 : Simple BAD_EQ
 * 비율에 기반한 기본적인 BAD_EQ 오류 검출 (비율: 0.8)
 * @author JWYoon
 *
 */
public class BadEq1 {

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
            if(objA == objB) {} // @violation
            if(objA.equals(objB)) {}
            if(objA.equals(objB)) {}
            if(objA.equals(objB)) {}
            if(objA.equals(objB)) {}
        }
    }

    class ReferentialMajor {
        OverrideEquals objA = null;
        OverrideEquals objB = null;

        public void method() {
            if(objA == objB) {}
            if(objA == objB) {}
            if(objA == objB) {}
            if(objA == objB) {}
            if(objA.equals (objB)) {} // @violation
        }
    }
}
