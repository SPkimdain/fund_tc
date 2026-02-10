import java.text.SimpleDateFormat;

public class SimpleDateFormatExample {
    public static void main(String[] args) {
        SimpleDateFormat sdf1 = new SimpleDateFormat("yyyy-MM-dd HH:mm:ss"); //@violation
        SimpleDateFormat sdf2 = new SimpleDateFormat(); //@violation
        SimpleDateFormat sdf3 = new SimpleDateFormat("pattern"); //@violation
        SimpleDateFormat sdf4 = new SimpleDateFormat("pattern", dateFormatSymbols); //@violation
        SimpleDateFormat sdf5 = new SimpleDateFormat("pattern", Locale.US); //@violation
    }
}