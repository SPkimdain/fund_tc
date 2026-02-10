package test.com.fasoo.javafinch.syn.rule.basic.privatecollection;

import java.util.Collection;

/**
 * PRIVATE_COLLECTION Test case 2 : Field access with methods
 * 메소드를 이용하여 필드값을 획득하는 경우
 * @author JWYoon
 *
 */
public class PrivateCollection2 {
    class PrivateCollection {
        private Collection<Object> privateCollection;

        private Collection<Object> getCollectionInner() {
            return this.privateCollection;
        }

        public Collection<Object> getCollectionMid() {
            return getCollectionInner(); // @violation
        }

        public Collection<Object> getCollection() {
            return getCollectionMid(); // @violation
        }
    }
}
