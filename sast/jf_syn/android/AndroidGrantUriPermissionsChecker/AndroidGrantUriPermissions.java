import android.content.Intent;

public class AndroidGrantUriPermissions extends Activity {
    @Override
    public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.main);

        Intent intent = new Intent();

        intent.addFlags(Intent.FLAG_GRANT_READ_URI_PERMISSION); // @violation
    }

    @Override
    public void onCreate_Safe(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.main);

        Intent intent = new Intent();

        // Safe, Unless intent.addFlags(Intent.FLAG_GRANT_READ_URI_PERMISSION) uses.
    }
}