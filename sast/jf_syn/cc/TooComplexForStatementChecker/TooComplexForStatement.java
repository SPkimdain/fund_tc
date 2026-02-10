package cc;

public class TooComplexForStatement {
    public void func() {
        int a, b, c;
        int s = 0;

        for(a=0; a<10; a++) {
            s++;
        }

        for(a=0, b=0, c=0; a<10; a++) { // @violation
            s++;
        }

        for(a=0; a<10; a++, b++, c++) { // @violation
            s++;
        }

        for(a=0, b=0, c=0; a<10; a++, b++, c++) { // @violation
            s++;
        }

        for(a=0, b=0; a<10; a++, b++) {
            s++;
        }
    }
}
