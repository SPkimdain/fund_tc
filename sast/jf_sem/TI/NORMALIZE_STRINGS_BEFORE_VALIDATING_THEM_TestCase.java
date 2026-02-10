package ti;

import java.util.regex.Pattern;
import java.util.regex.Matcher;
import java.text.Normalizer;
import java.text.Normalizer.Form;

class NORMALIZE_STRINGS_BEFORE_VALIDATING_THEM_TestCase {
    void test() {
        // String s may be user controllable
        // \uFE64 is normalized to < and \uFE65 is normalized to > using NFKC
        String s = "\uFE64" + "script" + "\uFE65";

        // Validate
        Pattern pattern = Pattern.compile("[<>]"); // Check for angle brackets
        Matcher matcher = pattern.matcher(s); /* BUG */
        if (matcher.find()) {
            // Found black listed tag
            throw new IllegalStateException();
        } else {
            // ...
        }

        // Normalize
        s = Normalizer.normalize(s, Form.NFKC);
    }
    void testSafe() {
        String s = "\uFE64" + "script" + "\uFE65";

        // Normalize
        s = Normalizer.normalize(s, Form.NFKC);

        // Validate
        Pattern pattern = Pattern.compile("[<>]");
        Matcher matcher = pattern.matcher(s);
        if (matcher.find()) {
            // Found blacklisted tag
            throw new IllegalStateException();
        } else {
            // ...
        }
    }
}