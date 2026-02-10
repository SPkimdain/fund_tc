package cj;

import java.util.Properties;

class AITest {
    void test(int i, Properties p) {
        String x = p.getProperty("env");
        String y = x;
        if(i > 0) {
            y = "safe";
            if(i > 10) {
                y = x;
            }
        }
        test2(y);
        String z = "z";
        if(i > 0) {
            System.out.println("z");
        }
        System.out.println(z);
    }
    void test2(String x) {
        String z = x;
        System.out.println(z);
        dangerousSink(z);
    }
    void dangerousSink(String x) {
        System.out.println(x);
    }
}