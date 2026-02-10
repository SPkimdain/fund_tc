import java.lang.Thread;

public class SecurityInfiniteLoop {
    public int nop() {
        while (true) {}                 // @violation
    }

    public final int DURATION=10000; // in milliseconds

    public void nop(int b) throws InterruptedException {
        int a = null;
        while(a <= b) {                  // @violation

        }

        while (true) {                  /* Safe */
            // Useful operations
            Thread.sleep(DURATION);
        }

        while (1) {                  /* Safe */
            // Useful operations
            Thread.yield();
        }

        while (1) {                  // @violation
        }

        /* FLAW: Infinite Loop - do {} with no break point */
        do {
            IO.writeLine(i);
            i = (i + 1) % 256;
        } while(i >= 0);

        /* FLAW: Infinite Loop - for() with no break point */
        for(int i = 0; i >= 0; i = (i + 1) % 256)
        {
            IO.writeLine(i);
        }

        /* FLAW: Infinite Loop - while() with no break point */
        while(i >= 0)
        {
            IO.writeLine(i);
            i = (i + 1) % 256;
        }

        for(;;) {                    /* Safe */
            Thread.sleep(1000);
        }

        while(true) {        /* Safe */
            break;
        }

        for(;;) {            /* Safe */
            break;
        }

        do {                 /* Safe */
            break;
        } while(true);

        ResultSet results = new ResultSet();
        while (results.next())  {               /* Safe */
            TR row = new TR();

            for (int i = 1; i < (numColumns + 1); i++) /* Safe */
            {

                t.addElement(row);
            }
        }

        while((read = fin.read(b)) != -1) {      /* Safe */
            outs.write(b,0,read);
        }

        while((start != strLen) && (stripChars.index(str.charAt(start)) != -1)) { /* Safe */
            start++;
        }


        String[] temp = { "aa", "bb", "cc" };
        for (String el : temp) {
            el = temp.toString();
            el = el.toString();
        }
    }
}
