package cc;

import com.test.A;
import com.test.B; import com.test.C; // @violation

public class UseOneStatementPerLine {
    public void funcA() {}
    public void funcB() {} public void funcC() {} // @violation

    public void funcD() {
        int a;
        int b; int c; // @violation

        for(int i=0; i<10; i++) {
            b = i;
        }

        for(int j=0; j<10; j++) { c = j; } // @violation
    }

    Comparator<Integer> lambdaTest1 = () -> {
        int x; int y; // @violation
    };

    Comparator<Integer> lambdaTest2 = () -> {
        int x;
        int y;
    };

    Comparator<Integer> lambdaTest3 = (int x, int y) -> { x = y; }; // @violation

    Comparator<Integer> lambdaTest4 = (int x, int y) -> {
        x = y;
    };
}