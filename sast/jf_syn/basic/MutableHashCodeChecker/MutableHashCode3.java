package test.com.fasoo.javafinch.syn.rule.basic.mutablehashcode;

import java.util.HashMap;
import java.util.Map;

/**
 * MUTABLE_HASHCODE Test case 3 : Field accessing with methods - Multi-level
 * 여러 메소드를 순서대로 거쳐 필드값을 획득하는 경우
 * @author JWYoon
 *
 */
public class MutableHashCode3 {
    private int mutable;

    public MutableHashCode3(int value) {
        mutable = value;
    }

    public int getMutableInner() {
        return this.mutable;
    }

    public int getMutableMid() {
        return getMutableInner();
    }

    public int getMutable() {
        return getMutableMid();
    }

    public void setMutableInner(int mutable) {
        this.mutable = mutable;
    }

    public void setMutableMid(int mutable) {
        setMutableInner(mutable);
    }

    public void setMutable(int mutable) {
        setMutableMid(mutable);
    }

    public int hashCode() {
        return getMutable(); // @violation
    }

    @SuppressWarnings("unchecked")
    public static void main(String[] args) {
        @SuppressWarnings("rawtypes")
        Map map = new HashMap();
        MutableHashCode3 hashClass = new MutableHashCode3(5);

        map.put(hashClass, 5);
        hashClass.setMutable(20);
    }
}
