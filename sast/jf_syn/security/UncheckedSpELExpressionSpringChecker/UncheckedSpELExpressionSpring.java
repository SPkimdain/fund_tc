//UNCHECKED_SPEL_EXPRESSION.SPRING
package security;

import javax.servlet.http.HttpServletRequest;
import java.util.Hashtable;
import org.springframework.expression.spel.standard.*;

public class UncheckedSpelExpressionSpring extends HttpServlet {

    public void testMethod(HttpServletRequest request) throws Exception {
        try {
            HashSet<String> whiteList = new HashSet<String>();

            String expression = request.getParameter("input");
            String expression2 = request.getParameter("input");
            String expression3 = request.getParameter("input");
            SpelExpressionParser parser = new SpelExpressionParser();
            SpelExpression expr = parser.parseRaw(expression);  // @violation
            expr = parser.parseRaw(request.getParameter("input"));  // @violation

            if (!whiteList.contains(expression2)) {
                throw new Exception();
            }
            expr = parser.parseRaw(expression2);  /* Safe */

            if(!checkParam(expression3)) {
                throw new Exception();
            }
            expr = parser.parseRaw(expression3);  /* Safe */
            //...
        } catch (Exception e) {
            //..
        }
	}

    public boolean checkParam(String inputData) {
        return inputData;
    }
}