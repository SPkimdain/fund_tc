package test.com.fasoo.javafinch.syn.rule.basic.mutablehashcode;

import java.util.HashMap;
import java.util.Map;

/**
 * MUTABLE_HASHCODE Test case 6 : Variable is considered as final since initialized only once after declared
 * 변수가 생성 후 딱 한번만 값이 설정(초기화) 되어 final로 간주되는 경우
 * @author JWYoon
 *
 */
public class MutableHashCode6 {
    private int mutable;

    public MutableHashCode6(int value) {
        mutable = value;
    }

    public int hashCode() {
        return this.mutable; // Not bug
    }

    @SuppressWarnings("unchecked")
    public static void main(String[] args) {
        @SuppressWarnings("rawtypes")
        Map map = new HashMap();
        MutableHashCode6 hashClass = new MutableHashCode6(6);

        map.put(hashClass, 6);
    }
}
