package cc;

import java.lang.String;

public class DoNotAppendStrings {

    private String s1;

    private class Inner {
        public String is1;
        private String is2;

        public Inner(String is1, String is2) {
            this.is1 = is1;
            this.is2 = is2;
        }

        public String getIs2() {
            return is2;
        }
    }

    public void func() {
        String s2, s3;
        int i1 = 0;

        String[] sarr = { "X", "Y", "Z" };
        String[][] s2arr = { {"X", "Y"}, {"Z", "Q"}};

        Inner inner = new Inner("E", "F");

        s2 = "a" + "b"; // @violation
        s3 = "a" + s2; // @violation
        s2 = ("a" + s1) + "b"; // @violation 2
        s2 = i1 + s2; // @violation
        s3 = s1 + " " + i1; // @violation
        s2 = i1 + inner.is1; // @violation
        s3 = i1 + inner.getIs2(); // @violation
        s2 = i1 + sarr[0]; // @violation
        s3 = i1 + s2arr[0][1]; // @violation
        s2 += "a"; // @violation
    }

    Comparator<String> lambda1 = () -> "a" + "b"; // @violation
    Comparator<String> lambda2 = (String tmp) -> tmp + "a"; // @violation
    Comparator<String> lambda3 = (String tmp) -> {
        return (tmp + "a") + "b";   // @violation 2
    };
}
