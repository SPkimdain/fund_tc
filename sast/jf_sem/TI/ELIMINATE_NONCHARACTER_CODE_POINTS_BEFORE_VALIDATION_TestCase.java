package ti;

import java.text.Normalizer;
import java.text.Normalizer.Form;
import java.util.regex.Pattern;
import java.util.regex.Matcher;

class ELIMINATE_NONCHARACTER_CODE_POINTS_BEFORE_VALIDATION_TestCase {
    public void test() {
        // "\uFEFF" is a non-character code point
        String s = "<scr" + "\uFEFF" + "ipt>";
        s = Normalizer.normalize(s, Form.NFKC);
        // Input validation
        Pattern pattern = Pattern.compile("<script>");
        Matcher matcher = pattern.matcher(s); /* BUG */
        if (matcher.find()) {
            System.out.println("Found black listed tag");
        } else {
            // ...
        }

        // Deletes all non-valid characters
        s = s.replaceAll("[^\\p{ASCII}]", "");
        // s now contains "<script>"
    }

    public void testSafe() {
        String s = "<scr" + "\uFEFF" + "ipt>";

        s = Normalizer.normalize(s, Form.NFKC);
        // Replaces all non-valid characters with unicode U+FFFD
        s = s.replaceAll("[^\\p{ASCII}]", "\uFFFD");

        Pattern pattern = Pattern.compile("<script>");
        Matcher matcher = pattern.matcher(s);
        if (matcher.find()) {
            System.out.println("Found blacklisted tag");
        } else {
            // ...
        }
    }
}