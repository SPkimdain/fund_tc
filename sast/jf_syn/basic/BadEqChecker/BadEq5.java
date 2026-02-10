package test.com.fasoo.javafinch.syn.rule.basic.badeq;

/**
 * BAD_EQ Test case 5 : Class-level checking
 * 클래스 단위로 개수를 비교, 검출하는지 확인
 * @author JWYoon
 *
 */
public class BadEq5 {

    class OverrideEquals {
        public String name;

        public boolean equals(Object o) {
            OverrideEquals other = (OverrideEquals)o;
            return(other.name.equals(this.name));
        }
    }

    class BugExisting {
        OverrideEquals objA = null;
        OverrideEquals objB = null;

        public void methodOne() {
            if(objA == objB) {} // @violation
            if(objA.equals(objB)) {}
            if(objA.equals(objB)) {}
            if(objA.equals(objB)) {}
            if(objA.equals(objB)) {}
        }

        public void methodTwo() {
            if(objA.equals(objB)) {}
            if(objA == objB) {} // @violation
            if(objA.equals(objB)) {}
            if(objA.equals(objB)) {}
            if(objA.equals(objB)) {}
        }

        public void methodThree() {
            if(objA.equals(objB)) {}
            if(objA.equals(objB)) {}
            if(objA == objB) {} // @violation
            if(objA.equals(objB)) {}
            if(objA.equals(objB)) {}
        }
    }

    class BugNotExisting {
        OverrideEquals objA = null;
        OverrideEquals objB = null;

        public void methodOne() {
            if(objA == objB) {}
            if(objA.equals(objB)) {}
            if(objA.equals(objB)) {}
            if(objA.equals(objB)) {}
            if(objA.equals(objB)) {}
        }

        public void methodTwo() {
            if(objA.equals(objB)) {}
            if(objA == objB) {}
            if(objA == objB) {}
            if(objA == objB) {}
            if(objA.equals(objB)) {}
        }

        public void methodThree() {
            if(objA == objB) {}
            if(objA == objB) {}
            if(objA == objB) {}
            if(objA.equals(objB)) {}
            if(objA.equals(objB)) {}
        }
    }
}
