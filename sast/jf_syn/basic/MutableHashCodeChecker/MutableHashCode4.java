package test.com.fasoo.javafinch.syn.rule.basic.mutablehashcode;

import java.util.HashMap;
import java.util.Map;

/**
 * MUTABLE_HASHCODE Test case 4 : Final variable
 * Final 필드일 경우 오류 없음 인식 여부 확인
 * @author JWYoon
 *
 */
public class MutableHashCode4 {
    private final int mutable;

    public MutableHashCode4(int value) {
        mutable = value;
    }

    public int hashCode() {
        return this.mutable; // Not bug
    }

    @SuppressWarnings("unchecked")
    public static void main(String[] args) {
        @SuppressWarnings("rawtypes")
        Map map = new HashMap();
        MutableHashCode4 hashClass = new MutableHashCode4(5);

        map.put(hashClass, 5);
    }
}
