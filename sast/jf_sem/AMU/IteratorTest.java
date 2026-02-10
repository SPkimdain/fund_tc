package amu;

import java.util.*;

public class IteratorTest {
    void safeDoubleNext() {
        List<String> strList = new LinkedList<String>();
        strList.add("one");
        strList.add("two");
        strList.add("three");
        Iterator strIter = strList.iterator();

        while(strIter.hasNext()) {
            String v = (String) strIter.next();
            if(v.length() > 5) {
                strIter.remove();
                continue;
            }

            if(v.length() > 0) {
                strIter.remove();
            }
        }
    }
    void doubleNext() {
        List<String> strList = new LinkedList<String>();
        strList.add("one");
        strList.add("two");
        strList.add("three");
        Iterator strIter = strList.iterator();

        while(strIter.hasNext()) {
            String v = (String) strIter.next();
            if(v.length() > 5) {
                strIter.remove();
            }

            if(v.length() > 0) {
                strIter.remove(); /* BUG */
            }
        }
    }
    void justNext() {
        List<String> strList = new LinkedList<String>();
        strList.add("one");
        strList.add("two");
        strList.add("three");
        ListIterator strIter = strList.listIterator();

        String v = (String) strIter.next(); /* BUG */
        if(v.length() > 5) {
            System.out.println("ahh!");
        }
    }
    void justPrev() {
        List<String> strList = new LinkedList<String>();
        strList.add("one");
        strList.add("two");
        strList.add("three");
        ListIterator strIter = strList.listIterator();

        String v = (String) strIter.previous(); /* BUG */
        if(v.length() > 5) {
            System.out.println("ahh!");
        }
    }
}
