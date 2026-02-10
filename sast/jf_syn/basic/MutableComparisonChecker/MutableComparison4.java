package test.com.fasoo.javafinch.syn.rule.basic.mutablecomparison;

import java.util.SortedSet;
import java.util.TreeSet;

/**
 * MUTABLE_COMPARISON Test case 4 : Accessing final field
 * Final 필드일 경우 오류 없음 인식 여부 확인
 * @author JWYoon
 *
 */
public class MutableComparison4 {
    @SuppressWarnings("rawtypes")
    class MutableValue implements Comparable {
        public final int value;

        public MutableValue(int value) {
            this.value = value;
        }

        public int getValue() {
            return this.value;
        }

        @Override
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
    }
}
