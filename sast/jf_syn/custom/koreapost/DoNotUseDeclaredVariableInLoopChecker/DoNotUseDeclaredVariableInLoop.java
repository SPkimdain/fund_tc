import org.jetbrains.annotations.NotNull;

import java.util.*;

class DoNotUseDeclaredVariableInLoop {
    public void violation1() {
        int index = 0;
        while(index < 10) {
            String idx = "인덱스";      // @violation

            index++;
        }
    }

    public void violation2() {
        int index = 0;
        do {
            String idx = "인덱스";      // @violation

            index++;
        } while(index < 10);
    }

    public void violation3() {
        for(int i=0; i<10; i++) {
            String idx = "인덱스";      // @violation
        }
    }

    public void violation4() {
        for(String str: list1) {
            List<String> list = new List<String>() {
                @Override
                public int size() {
                    String idx = "인덱스";      /* SAFE */
                    return 0;
                }
            };
        }
    }

    public void good1() {
        String idx = "인덱스";          /* SAFE */

        int index = 0;
        while (index < 10) {
            index++;
        }
    }

    public void good2() {
        String idx = "인덱스";          /* SAFE */

        int index = 0;
        do {
            index++;
        } while (index < 10);
    }

    public void good3() {
        String idx = "인덱스";          /* SAFE */
        for (int i = 0; i < 10; i++) {
            // ...
        }
    }

    public void good4() {
        for (int i = 0; i < 10; i++) {
            String safeIdx = "인덱스"; /* SAFE */
        }
    }
}