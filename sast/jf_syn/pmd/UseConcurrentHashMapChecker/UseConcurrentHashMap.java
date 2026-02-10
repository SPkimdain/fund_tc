package pmd;

import java.util.Map;
import java.util.concurrent.ConcurrentHashMap;
import java.util.HashMap;
import java.util.TreeMap;
import java.util.*;

public class UseConcurrentHashMap {

    Map map = new HashMap(); // @violation

    void test() {
        Map map1;

        Map map2;

        map1 = new HashMap(); // @violation

        map2 = new HashMap(); // @violation

        Map map2 = new HashMap(); // @violation

        Map map3 = new TreeMap(); // @violation

        Map map4 = new ConcurrentHashMap(); /* Safe */

        Map<String, String> map5 = new HashMap<String, String>(); // @violation
    }
}