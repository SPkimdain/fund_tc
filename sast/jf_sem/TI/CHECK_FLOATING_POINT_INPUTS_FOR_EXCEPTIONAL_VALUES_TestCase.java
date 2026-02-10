package ti;

import java.util.Properties;
import javax.servlet.http.HttpServletRequest;

class CHECK_FLOATING_POINT_INPUTS_FOR_EXCEPTIONAL_VALUES_TestCase {
    double currentBalance; // User's cash balance
    void testSafe(Properties input) {
        double val = 0;
        try {
            String userInput = input.getProperty("number");
            val = Double.valueOf(userInput);
        } catch (NumberFormatException e) {
            // Handle input format error
        }

        if (Double.isInfinite(val)){
            // Handle infinity error
        }

        if (Double.isNaN(val)) {
            // Handle NaN error
        }

        if (val >= Double.MAX_VALUE - currentBalance) {
            // Handle range error
        }
        currentBalance += val;
    }
    void test(Properties input, HttpServletRequest request) {
        double val = 0;
        try {
            String userInput = request.getParameter("number"); // input.getProperty("number");
            val = Double.valueOf(userInput);
        } catch (NumberFormatException e) {
            // Handle input format error
        }

        if (val >= Double.MAX_VALUE - currentBalance) {
            // Handle range error
        }

        currentBalance += val; /* BUG 2 */
    }
    void test2(Properties input, HttpServletRequest request) {
        double val = 0;
        try {
            String userInput = request.getParameter("number"); //input.getProperty("number");
            val = Double.valueOf(userInput);
        } catch (NumberFormatException e) {
            // Handle input format error
        }

        if (Double.isNaN(val)) {
            // Handle NaN error
        }

        if (val >= Double.MAX_VALUE - currentBalance) {
            // Handle range error
        }
        currentBalance += val; /* BUG */
    }
    void test3(Properties input, HttpServletRequest request) {
        double val = 0;
        try {
            String userInput = request.getParameter("number"); //input.getProperty("number");
            val = Double.valueOf(userInput);
        } catch (NumberFormatException e) {
            // Handle input format error
        }

        if (Double.isInfinite(val)){
            // Handle infinity error
        }

        if (val >= Double.MAX_VALUE - currentBalance) {
            // Handle range error
        }
        currentBalance += val; /* BUG */
    }
}