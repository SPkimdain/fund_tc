package misuse;

import java.lang.Thread;

public class InfiniteRecursiveCall {

    public void infinite() {    // @violation

        boolean condition = false;
        Thread t = new Thread();
        infinite();             // RecursiveCall
        infinite("a", t);       /* Safe */

        if(condition) {
            infinite();         /* Safe */
        } else if (condition) {
            infinite();         /* Safe */
        }
    }

    @Override
    public String getName() {
        return InfiniteRecursiveCall.class.getName();
    }

    public void infinite(String a, Thread t) {  // @violation
        boolean condition = false;
        infinite();             /* Safe */
        infinite("a", t);       // RecursiveCall

        if(condition) {
            infinite("a", t);         /* Safe */
        } else if (condition) {
            infinite("a", t);         /* Safe */
        }
    }

    public void test(Object o) {
        test((Thread)o); /* Safe */
    }

    public void test(Thread t) {
        test((Object)t); /* Safe */
    }

    public void test2(Object o) {   // @violation
        test2((Object)o); // RecursiveCall
    }

    public void test2(Thread t) {   // @violation
        test2((Thread)t); // RecursiveCall
    }

    public void test3(Thread foo, Object bar) {
        test3((Thread)foo, (Thread)bar); /* Safe */
    }

    public void test3(Thread foo, Thread bar) { // @violation
        test3((Thread)foo, (Thread)bar); // RecursiveCall
    }

    public void overloadTest(String[] arg) {
        for (String a: arg) {
            System.out.println(a);
        }
    }

    public void overloadTest(String arg) {
        overloadTest(new String[]{"a"}); /* Safe */
    }

    public String getRecentWorkDate(Calendar cal) {
        int day = cal.get(Calendar.DAY_OF_WEEK);

        if (day != Calendar.SUNDAY && day != Calendar.SATURDAY && !checkHoliday(cal)) {
            return getYYYYMMDD(cal);    /* Safe */
        }
        cal.add(Calendar.DATA, 1);
        return getRecentWorkDate(cal);  /* Safe */
    }

    public String tmp(int a) {
        if (a == 0) {
            return 1;   /* Safe */
        }
        return tmp(a);
    }

    public String tmp2(int a) {     // @violation
        if (a <= 1) {
            return tmp2(a);
        } else {
            return tmp2(a) + tmp2(a+1);
        }
    }

    public String tmp3(int a) {
        if (a == 1) {
            return tmp3(a);
        }
        return 1;
    }

    public String tmp5(int a) {
        if (a == 1) {
            if (a == 4) {
                tmp5(a);
            } else if (a == 5) {
                tmp5(a);
            } else {
                return 1;
                tmp5(a);
            }
        }
    }

    public String tmp6(int a) { // @violation
        if (a == 1) {
            tmp6(a);
            return 1; /* Safe */
        } else {
            tmp6(a);
        }
    }

    public String aa1(int a) {
        if (a==1) {
            aa1(a);
        } else if (aa=1) {
            aa1(a);
        }
    }

    public String aa2(int a) {
        if (a==1) {
            aa2(a);
            aa2(a);
        } else if (a==2) {
            aa2(a);
        } else {
            aa1(a);
        }
    }
}
