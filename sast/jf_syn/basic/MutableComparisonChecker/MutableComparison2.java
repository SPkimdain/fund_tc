package test.com.fasoo.javafinch.syn.rule.basic.mutablecomparison;

import java.util.SortedSet;
import java.util.TreeSet;

/**
 * MUTABLE_COMPARISON Test case 2 : Simple MUTABLE_COMPARISON - Field access using methods
 * 기본적인 MUTABLE_COMPARISON 오류 검출 - 메소드를 이용하여 필드값 획득
 * @author JWYoon
 *
 */
public class MutableComparison2 {
    @SuppressWarnings("rawtypes")
    class MutableValue implements Comparable {
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

        @Override
        public int compareTo(Object arg0) {
            MutableValue itemArg0 = (MutableValue)arg0;

            // There are two bugs because the next expression uses two .getValue()
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

        i.setValue(63);
    }
}
