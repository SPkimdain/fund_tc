package test.com.fasoo.javafinch.syn.rule.basic.badeq;

/**
 * BAD_EQ Test case 3 : Considering static field
 * Static field의 경우 무시하는지 확인
 * @author JWYoon
 *
 */
public class BadEq3 {

    class OverrideEquals {
        public String name;

        public boolean equals(Object o) {
            OverrideEquals other = (OverrideEquals)o;
            return(other.name.equals(this.name));
        }
    }

    static OverrideEquals objS;

    public class StructuralMajor {
        OverrideEquals objA = null;

        public void method() {
            if(objS == objA) {}
            if(objS.equals(objA)) {}
            if(objS.equals(objA)) {}
            if(objS.equals(objA)) {}
            if(objS.equals(objA)) {}
        }
    }

    class ReferentialMajor {
        OverrideEquals objA = null;

        public void method() {
            if(objS == objA) {}
            if(objS == objA) {}
            if(objS == objA) {}
            if(objS == objA) {}
            if(objS.equals (objA)) {}
        }
    }
}