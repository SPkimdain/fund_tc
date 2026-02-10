package nd;

import java.lang.Exception;
import java.util.*;
import java.util.Map;
import java.lang.Boolean;

class CatchedND2 {
    String get(String k) throws Exception {
        Exception e = new Exception();
        if (k == null) throw e;

        return k;
    }
    void foo (String str) throws Exception {
        Object o = get(str);

        if(o instanceof String ){}
        else if (o.equals(Boolean.TRUE)) {} /* SAFE */
    }
}