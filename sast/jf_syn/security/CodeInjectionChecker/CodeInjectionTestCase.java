import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestMethod;
import org.springframework.web.bind.annotation.RequestParam;

import javax.script.ScriptEngine;
import javax.script.ScriptEngineManager;
import javax.script.ScriptException;
import java.io.IOException;
import java.util.HashSet;
import java.util.Set;
import javax.servlet.http.HttpServletRequest;

@RequestMapping(value = "/execute", method = RequestMethod.GET)
public class CodeInjectionTestCase {
    @RequestMapping(value = "/execute", method = RequestMethod.GET)
    public String badTestCase1(@RequestParam("src") String src) throws ScriptException {
        ScriptEngineManager scriptEngineManager = new ScriptEngineManager();

        ScriptEngine scriptEngine = scriptEngineManager.getEngineByName("javascript");

        String retValue = (String) scriptEngine.eval(src); // @violation
        return retValue;
    }

    // Good Case
    @RequestMapping(value = "/execute", method = RequestMethod.GET)
    public String goodTestCase1(@RequestParam("src") String src) throws ScriptException {
        ScriptEngineManager scriptEngineManager = new ScriptEngineManager();

        ScriptEngine scriptEngine = scriptEngineManager.getEngineByName("javascript");

        if(!src.matches("[\\w]*")) { // check
            throw new IllegalArgumentException();
        }

        String retValue = (String) scriptEngine.eval(src); /* SAFE */
        return retValue;
    }

    // Good Case
    @RequestMapping(value = "/execute", method = RequestMethod.GET)
    public String goodTestCase2(@RequestParam("src") String src) throws ScriptException {
        Set<String> whiteList = new HashSet<String>();

        ScriptEngineManager scriptEngineManager = new ScriptEngineManager();

        ScriptEngine scriptEngine = scriptEngineManager.getEngineByName("javascript");

        if(!whiteList.contains(src)) {
            throw new IllegalArgumentException();
        }

        String retValue = (String) scriptEngine.eval(src); /* SAFE */
        return retValue;
    }

    @RequestMapping(value = "/execute", method = RequestMethod.GET)
    public String goodTestCase3(@RequestParam("src") String src) throws ScriptException {
        ScriptEngineManager scriptEngineManager = new ScriptEngineManager();

        ScriptEngine scriptEngine = scriptEngineManager.getEngineByName("javascript");

        if(!checkParam(src)) {
            throw new IllegalArgumentException();
        }

        String retValue = (String) scriptEngine.eval(src); /* SAFE */
        return retValue;
    }
}