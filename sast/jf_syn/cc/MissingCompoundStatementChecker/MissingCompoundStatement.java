package cc;

public class MissingCompoundStatement {
    public void func() {
        int i = 0;
        int j = 0;

        if(i == 0)        // @violation






            j = 10;

        if(i == 0) {
            j++;
        }

        for(i=0; i<10; i++)     // @violation
            j = 10;

        for(i = 0; i < 10; i++) {
            j++;
        }

        while(i < 10)       // @violation
            i--;

        while(i < 10) {
            i--;
        }

        do                  // @violation
            i--;
        while(i < 10);

        do {
            i--;
        } while(i < 10);
    }
}