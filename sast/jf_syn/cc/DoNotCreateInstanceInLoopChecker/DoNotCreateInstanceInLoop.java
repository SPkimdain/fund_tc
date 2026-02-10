package cc;
import java.lang.String;
import java.math.BigDecimal;

public class DoNotCreateInstanceInLoop {

    private class Inner {
        private int iField;

        public Inner(int iField) {
            this.iField = iField;
        }
    }

    public DoNotCreateInstanceInLoop() {
        // Do something ...
    }

    public void useInner(Inner inner) {
        // Do something ...
    }

    public void func() {

        String s1 = new String();
        var v1 = new ArrayList<String>();
        DoNotCreateInstanceInLoop t1 = new DoNotCreateInstanceInLoop();
        useInner(new Inner(0));

        String s2 = null;
        for(int i=0; i<10; i++) {
            s2 = new String(); /* Safe */
            var v2 = new ArrayList<String>();
            DoNotCreateInstanceInLoop t2 = new DoNotCreateInstanceInLoop(); // @violation
            useInner(new Inner(0)); /* Safe */
        }

        int cnt = 0;
        while(cnt < 10) {
            String s3 = new String(); // @violation
            var v3 = new ArrayList<String>();
            DoNotCreateInstanceInLoop t3 = new DoNotCreateInstanceInLoop(); // @violation
            useInner(new Inner(0)); /* Safe */
            cnt++;
        }

        cnt = 0;
        do {
            String s4 = new String(); // @violation
            var v4 = new ArrayList<String>();
            DoNotCreateInstanceInLoop t4 = new DoNotCreateInstanceInLoop(); // @violation
            useInner(new Inner(0)); /* Safe */
            cnt++;
        } while(cnt < 10);

        cnt = 0;
        do {
            for(int i=0; i<10; i++) {
                String s5 = new String(); // @violation
            }
            var v5 = new ArrayList<String>();
            DoNotCreateInstanceInLoop t5 = new DoNotCreateInstanceInLoop(); // @violation
            while(cnt < 5) {
                useInner(new Inner(0)); /* Safe */
                cnt++;
            }
            cnt++;
        } while(cnt < 10);

        for(int i=0; i<10; i++) {
            if(new BigDecimal("123").compareTo(new BigDecimal("0"))) { /* SAFE */

            }
        }

        int cnt = 0;
        while(cnt < 10) {
            if(new BigDecimal("123").compareTo(new BigDecimal("0"))) { /* SAFE */

            }
        }

        cnt = 0;
        do {
            if(new BigDecimal("123").compareTo(new BigDecimal("0"))) { /* SAFE */

            }
        } while(cnt < 10);

        cnt = 0;
        do {
            for(int i=0; i<10; i++) {
                if(new BigDecimal("123").compareTo(new BigDecimal("0"))) { /* SAFE */

                }
            }

            while(cnt < 5) {
                if(new BigDecimal("123").compareTo(new BigDecimal("0"))) { /* SAFE */

                }
                cnt++;
            }
            cnt++;
        } while(cnt < 10);
    }
}