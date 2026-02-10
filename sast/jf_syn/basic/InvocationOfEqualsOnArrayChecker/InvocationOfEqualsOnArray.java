package basic;

public class InvocationOfEqualsOnArray {
    public void test1() {
        int [] a = new int[3];
        int [] b = new int[3];
        for (int i = 0; i < a.length; i++) {
            a[i] = i * 3;
            b[i] = i + 2;
        }

        if (a.equals(b)) { // @violation
            System.out.println("a == b");
        }
    }

    public void test2() {
        String [] strList1 = {"a", "b"};
        String [] strList2 = {"a", "2"};

        for(int i=0; i< strList1.length; i++) {
            if (strList1[i].equals(strList2[0])) {    // safe
            }
        }
    }
}