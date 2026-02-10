package test.com.fasoo.javafinch.syn.rule.basic.mutablehashcode;

import java.util.HashMap;
import java.util.Map;

/**
 * MUTABLE_HASHCODE Test case 1 : Simple MUTABLE_HASHCODE - Direct field accessing
 * 기본적인 MUTABLE_HASHCODE 오류 검출 - 필드에 직접 접근
 * @author JWYoon
 *
 */
public class MutableHashCode1 {
    private int mutable;

    public MutableHashCode1(int value) {
        mutable = value;
    }

    public int hashCode() {
        return this.mutable; // @violation
    }

    @SuppressWarnings("unchecked")
    public static void main(String[] args) {
        @SuppressWarnings("rawtypes")
        Map map = new HashMap();
        MutableHashCode1 hashClass = new MutableHashCode1(5);

        map.put(hashClass, 5);
        hashClass.mutable = 20;
    }
}
