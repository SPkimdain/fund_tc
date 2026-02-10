package ti;

import javax.servlet.http.HttpServletRequest;
import java.text.Normalizer;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class STRING_NORMALIZATION_REQUIRED_BEFORE_VALIDATION_TestCase {

    private void violation(HttpServletRequest request) {
        String s = request.getParameter("userInput");

        // Validate
        Pattern pattern = Pattern.compile("[<>]");  // Check for angle brackets
        Matcher matcher = pattern.matcher(s);       /* BUG */
        if (matcher.find()) {
            // Found black listed tag
            throw new IllegalStateException();
        } else {
            // ...
        }
    }

    private void good(HttpServletRequest request) {
        String s = request.getParameter("userInput");

        // Normalize
        s = Normalizer.normalize(s, Normalizer.Form.NFKC);

        // Validate
        Pattern pattern = Pattern.compile("[<>]");
        Matcher matcher = pattern.matcher(s);       /* GOOD */
        if (matcher.find()) {
            // Found blacklisted tag
            throw new IllegalStateException();
        } else {
            // ...
        }
    }
}