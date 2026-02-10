//UNCHECKED_OGNL_EXPRESSION
package security;

import javax.servlet.http.HttpServletRequest;
import java.util.Hashtable;
import org.apache.commons.ognl.*;

public class UncheckedOgnlExpression extends HttpServlet {

    public void testMethod(HttpServletRequest request) throws OgnlException {
        try {
            HashSet<String> whiteList = new HashSet<String>();

            String expression = request.getParameter("input");
            String expression2 = request.getParameter("input");
            String expression3 = request.getParameter("input");

            Object expr = Ognl.parseExpression(expression); // @violation
            expr = Ognl.parseExpression(request.getParameter("input"));  // @violation

            if (!whiteList.contains(expression2)) {
                throw new OgnlException();
            }
            expr = Ognl.parseExpression(expression2);  /* Safe */

            if(!checkParam(expression3)) {
                throw new OgnlException();
            }
            expr = Ognl.parseExpression(expression3);  /* Safe */
            //...
        } catch (OgnlException e) {
            //..
        }
	}

    public boolean checkParam(String inputData) {
        return inputData;
    }
}