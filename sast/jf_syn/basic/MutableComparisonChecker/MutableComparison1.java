package test.com.fasoo.javafinch.syn.rule.basic.mutablecomparison;

import java.util.SortedSet;
import java.util.TreeSet;

/**
 * MUTABLE_COMPARISON Test case 1 : Simple MUTABLE_COMPARISON - Direct field access
 * 기본적인 MUTABLE_COMPARISON 오류 검출 - 필드에 직접 접근
 * @author JWYoon
 *
 */
public class MutableComparison1 {
    @SuppressWarnings("rawtypes")
    class MutableValue implements Comparable {
        public int value;

        public MutableValue(int value) {
            this.value = value;
        }

        @Override
        public int compareTo(Object arg0) {
            MutableValue itemArg0 = (MutableValue)arg0;

            // There are two bugs because the next expression uses two .value
            // which accesses to the mutable field
            return this.value - itemArg0.value; // @violation 2
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

        i.value = 63;
    }
}
