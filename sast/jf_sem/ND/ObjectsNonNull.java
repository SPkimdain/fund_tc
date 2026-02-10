package nd;

import java.lang.Exception;
import java.lang.String;
import java.util.Objects;
import java.lang.Boolean;

class ObjectsNonNull {
    int foo (String str) throws Exception {
        int temp;
        if (str != null) temp=3;
        else temp=4;

        if (Objects.nonNull(str)) {
            return str.length(); /* SAFE */
        }
        return temp;
    }

    int foo2 (String str) throws Exception {
        int temp;
        if (str != null) temp=3;
        else temp=4;

        if (!Objects.nonNull(str)) {
            return str.length(); /* BUG */
        }
        return temp;
    }
}