package ti;

import java.util.Set;
import java.util.HashSet;
import java.util.Properties;
import java.nio.CharBuffer;
import java.util.regex.Pattern;
import java.util.regex.Matcher;
import javax.servlet.http.HttpServletRequest;

class SANITIZE_UNTRUSTED_DATA_PASSED_TO_A_REGEX_TestCase {
    static CharBuffer log;
    public static Set<String> suggestSearches(String search) {
        Set<String> searches = new HashSet<String>();

        // Construct regex dynamically from user string
        String regex = "(.*? +public\\[\\d+\\] +.*" + search + ".*)";

        Pattern keywordPattern = Pattern.compile(regex);
        Matcher logMatcher = keywordPattern.matcher(log);
        while (logMatcher.find()) {
            String found = logMatcher.group(1);
            searches.add(found);
        }
        return searches;
    }

    public static Set<String> suggestSearchesSafe(String search) {
        Set<String> searches = new HashSet<String>();

        StringBuilder sb = new StringBuilder(search.length());
        for (int i = 0; i < search.length(); ++i) {
            char ch = search.charAt(i);
            if (Character.isLetterOrDigit(ch) ||
                    ch == ' ' ||
                    ch == '\'') {
                sb.append(ch);
            }
        }
        search = sb.toString();

        // Construct regex dynamically from user string
        String regex = "(.*? +public\\[\\d+\\] +.*" + search + ".*)";

        Pattern keywordPattern = Pattern.compile(regex);
        Matcher logMatcher = keywordPattern.matcher(log);
        while (logMatcher.find()) {
            String found = logMatcher.group(1);
            searches.add(found);
        }
        return searches;
    }

   public static void test(Properties request, HttpServletRequest req) {
       String data = req.getParameter("data"); //request.getProperty("data");
       suggestSearchesSafe(data); /* BUG */ // NULL_RETURN_STD
       suggestSearches(data); /* BUG */
   }
}
