package test.com.fasoo.javafinch.syn.rule.basic.badeq;

/**
 * BAD_EQ Test case 4 : Dealing only with the class which overrides Object.equals()
 * Object.equals()를 오버라이드 한 클래스에 대해서만 동작하는지 확인
 * @author JWYoon
 *
 */
public class BadEq4 {

    class OverrideEquals extends NotOverrideEquals {
        public String name;

        public boolean equals(Object o) {
            OverrideEquals other = (OverrideEquals)o;
            return(other.name.equals(this.name));
        }
    }

    class NotOverrideEquals {
        public String name;
    }

    class StructuralMajor {
        NotOverrideEquals objA = null;
        OverrideEquals objB = null;

        public void method() {
            if(objA == objB) {}
            if(objA.equals(objB)) {}
            if(objA.equals(objB)) {}
            if(objA.equals(objB)) {}
            if(objA.equals(objB)) {}
        }
    }

    class ReferentialMajor {
        NotOverrideEquals objA = null;
        OverrideEquals objB = null;

        public void method() {
            if(objA == objB) {}
            if(objA == objB) {}
            if(objA == objB) {}
            if(objA == objB) {}
            if(objA.equals(objB)) {}
        }
    }
}
