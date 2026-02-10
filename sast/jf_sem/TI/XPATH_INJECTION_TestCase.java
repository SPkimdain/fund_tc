package ti;

import org.w3c.dom.NodeList;

import javax.xml.xpath.*;
import java.util.Properties;

import javax.servlet.http.HttpServletRequest;

/**
 * Writer: Gyuhang Shim
 * Date: 7/25/12
 */
/* OPT : -show_followers */
public class XPATH_INJECTION_TestCase {
    public void test(HttpServletRequest request, Object doc) throws XPathExpressionException {
        Properties props = new Properties();
        // 외부로부터 입력을 받음
        String name = request.getParameter("name"); //String name = props.getProperty("name");
        String passwd = request.getParameter("password"); //String passwd = props.getProperty("password");

        XPathFactory factory = XPathFactory.newInstance();
        XPath xpath = factory.newXPath();

        // 외부 입력이 xpath의 인자로 사용
        XPathExpression expr = xpath.compile("//users/user[login/text()='" + "tiger" + "' and password/text() = '" + passwd + "']/home_dir/text()"); /* BUG */

        Object result = expr.evaluate(doc, XPathConstants.NODESET);
        NodeList nodes = (NodeList) result;
        for (int i = 0; i < nodes.getLength(); i++) {
            String value = nodes.item(i).getNodeValue();
            if (value.indexOf(">") < 0) {
                System.out.println(value);
            }
        }
        xpath.evaluate("//users/user[login/text()='" + name + "'", null); /* BUG */
    }
}
