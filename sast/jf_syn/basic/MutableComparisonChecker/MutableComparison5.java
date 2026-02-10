package test.com.fasoo.javafinch.syn.rule.basic.mutablecomparison;

import java.util.SortedSet;
import java.util.TreeSet;

/**
 * MUTABLE_COMPARISON Test case 5 : Class is not inherited from Comparable class
 * Comparable 인터페이스로부터 구현된 클래스가 아닌 경우 오류 아님
 * @author JWYoon
 *
 */
public class MutableComparison5 {
    class MutableValue {
        public int value;

        public MutableValue(int value) {
            this.value = value;
        }

        public int getValue() {
            return this.value;
        }

        public void setValue(int value) {
            this.value = value;
        }

        // Not overriden from Comparable.compareTo
        public int compareTo(Object arg0) {
            MutableValue itemArg0 = (MutableValue)arg0;

            return this.value - itemArg0.value; // Not bug
        }
    }

    @SuppressWarnings("rawtypes")
    SortedSet sortedSet = new TreeSet();
    MutableValue i = new MutableValue(42);
    MutableValue j = new MutableValue(52);

    @SuppressWarnings("unchecked")
    public void method() {
        sortedSet.add(i);
        sortedSet.add(j);

        i.setValue(63);
    }
}
