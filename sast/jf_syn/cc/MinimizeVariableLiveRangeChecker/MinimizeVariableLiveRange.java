package cc;

public class MinimizeVariableLiveRange {
    public void test(int p1, String p2, boolean p3) {
        int x = 0; // @violation
        int a = 1; // OK with allow_decl_seq
        int b = 2; // may bad, but OK now

        if (p3) a += p1;
        else b += p1;

        int c = 10; // OK
        if (p3) {
            System.out.println("true");
            c += 1;
        } else {
            System.out.println("false");
            c += 2;
        }

        int d = 20; // may bad, but OK now
        if (p3) {
            System.out.println("true");
            d += x;

            int e = 30; // may bad, but OK now
            switch(x) {
                case 0:
                case 1:
                    d += 1;
                    break;
                case 2:
                    d += 3;
                    break;
                default: {
                    int e = 40; // re-declaration in local block
                    System.out.println(e); // this 'e' is 40, not 30... but engine cannot distinguish it
                    break;
                }
            }
            System.out.println(e);
        }
    }
}