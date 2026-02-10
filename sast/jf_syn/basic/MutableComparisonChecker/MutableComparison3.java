package test.com.fasoo.javafinch.syn.rule.basic.mutablecomparison;

import java.util.SortedSet;
import java.util.TreeSet;

/**
 * MUTABLE_COMPARISON Test case 3 : Field access using methods - Multi-level
 * 여러 메소드를 순서대로 거쳐 필드값을 획득하는 경우
 * @author JWYoon
 *
 */
public class MutableComparison3 {
    @SuppressWarnings("rawtypes")
    class MutableValue implements Comparable {
        public int value;

        public MutableValue(int value) {
            this.value = value;
        }

        public int getValueInner() {
            return this.value;
        }

        public int getValueMid() {
            return getValueInner();
        }

        public int getValue() {
            return getValueMid();
        }

        public void setValueInner(int value) {
            this.value = value;
        }

        public void setValueMid(int value) {
            setValueInner(value);
        }

        public void setValue(int value) {
            setValueMid(value);
        }

        @Override
        public int compareTo(Object arg0) {
            MutableValue itemArg0 = (MutableValue)arg0;

            // There are two bugs because the next expression uses two .getValue()
            // which accesses to the mutable field
            return this.getValue() - itemArg0.getValue(); // @violation 2
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
