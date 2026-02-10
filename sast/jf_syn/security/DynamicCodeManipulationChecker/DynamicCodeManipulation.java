//DYNAMIC_CODE_MANIPULATION
package security;

import javax.servlet.http.HttpServletRequest;
import java.util.Hashtable;
import javax.servlet.ServletRequest;
import javax.script.ScriptEngine;

public class DynamicCodeManipulation extends HttpServlet {

    @Override
    public void doGet(HttpServletRequest req, HttpServletResponse res) throws IOException {
        try (PrintWriter writer = res.getWriter()) {
            HashSet<String> whiteList = new HashSet<String>();

            String input = req.getParameter("input");
            String input2 = req.getParameter("input");
            String input3 = req.getParameter("input");
            ScriptEngine scriptEngine = ScriptEngineManager().getEngineByName("JavaScript");
            scriptEngine.eval(req.getParameter("input"));   // @violation
            scriptEngine.eval(input);   // @violation

            if (!whiteList.contains(input2)) {
                throw new IOException();
            }
            scriptEngine.eval(input2);   /* Safe */

            if(!checkParam(input3)) {
                throw new IOException();
            }
            scriptEngine.eval(input3);   /* Safe */

        } catch (IOException | ScriptException ex) {
            //Logger.getLogger(MyServlet.class.getName()).log(Level.SEVERE, null, ex);
        }
    }

    public boolean checkParam(String inputData) {
        return inputData;
    }
}