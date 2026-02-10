package test.com.fasoo.javafinch.syn.rule.basic.mutablehashcode;

import java.util.HashMap;
import java.util.Map;

/**
 * MUTABLE_HASHCODE Test case 2 : Simple MUTABLE_HASHCODE - Field accessing with methods
 * 기본적인 MUTABLE_HASHCODE 오류 검출 - 메소드를 이용하여 필드값 획득
 * @author JWYoon
 *
 */
public class MutableHashCode2 {
    private int mutable;

    public MutableHashCode2(int value) {
        mutable = value;
    }

    public int getMutable() {
        return this.mutable;
    }

    public void setMutable(int mutable) {
        this.mutable = mutable;
    }

    public int hashCode() {
        return getMutable(); // @violation
    }

    @SuppressWarnings("unchecked")
    public static void main(String[] args) {
        @SuppressWarnings("rawtypes")
        Map map = new HashMap();
        MutableHashCode2 hashClass = new MutableHashCode2(5);

        map.put(hashClass, 5);
        hashClass.setMutable(20);
    }
}
