package test.com.fasoo.javafinch.syn.rule.basic.mutablehashcode;

import java.util.HashMap;
import java.util.Map;

/**
 * MUTABLE_HASHCODE Test case 5 : Variable is considered as final since initialized only once
 * 변수가 생성 시 동시에 초기화 된 뒤 한번도 새로 설정되지 않아 final로 간주되는 경우
 * @author JWYoon
 *
 */
public class MutableHashCode5 {
    private int mutable = 5; // Initialized only once

    public MutableHashCode5() {
    }

    public int hashCode() {
        return this.mutable; // Not bug
    }

    @SuppressWarnings("unchecked")
    public static void main(String[] args) {
        @SuppressWarnings("rawtypes")
        Map map = new HashMap();
        MutableHashCode5 hashClass = new MutableHashCode5();

        map.put(hashClass, 5);
    }
}
