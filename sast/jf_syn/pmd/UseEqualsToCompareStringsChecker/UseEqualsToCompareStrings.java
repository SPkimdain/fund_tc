package src.test.java.pmd;

public class UseEqualsToCompareStrings {
    public boolean test1(String s) {
        if(null =="one")
            return true;
        return false;
    }
    public boolean test2() {
        if("one"=="one") // @violation
            return true;
        return false;
    }
    public boolean test3(String s1, String s2) {
        if(s1==s2) // @violation
            return true;
        return false;
    }
    public boolean test4(int n1, int n2) {
        if(n1==n2)
            return true;
        return false;
    }

    String a = "test";
    String b = "test";
    String good = a == b ? "equal" : "not equal";    // @violation
    String bad = a.equals(b) ? "equal" : "not equal";    /* SAFE */


}