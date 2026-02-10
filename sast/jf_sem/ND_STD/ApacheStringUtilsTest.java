package nd_std;

import java.lang.Exception;
import java.lang.String;
import org.apache.commons.lang.StringUtils;

class ApacheStringUtilsTest {
    void foo () throws Exception {
        String x = null;
        if (StringUtils.defaultString(null) == "") {
            int l = 1;
        }
        else {
            int l = x.length(); //not reachable, SAFE
        }
    }
}