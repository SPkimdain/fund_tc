import android.content.Context;

public class SecurityFileGlobalAccess {
    public void onCreate_unsafe(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        try {
            FileOutputStream fOut = openFileOutput("test", Context.MODE_WORLD_READABLE);     // @violation
            OutputStreamWriter out1 = new OutputStreamWriter(fOut);
            out1.write("Hello World");
            out1.close();
            fOut.close();
        } catch (Throwable t) {
        }
    }

    public void onCreate_unsafe2(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        try {
            FileOutputStream fOut = openFileOutput("test", MODE_WORLD_WRITEABLE);     // @violation
            OutputStreamWriter out1 = new OutputStreamWriter(fOut);
            out1.write("Hello World");
            out1.close();
            fOut.close();
        } catch (Throwable t) {
        }
    }

    public void onCreate_safe(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        try {
            FileOutputStream fOut = openFileOutput("test", MODE_PRIVATE);     /* Safe */
            OutputStreamWriter out1 = new OutputStreamWriter(fOut);
            out1.write("Hello World");
            out1.close();
            fOut.close();
        } catch (Throwable t) {
        }
    }
}

