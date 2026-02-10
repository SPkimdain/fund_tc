package test.com.fasoo.javafinch.syn.rule.basic.privatecollection;

import java.util.Collection;

/**
 * PRIVATE_COLLECTION Test case 4 : Complex field access with methods
 * 복잡한 메소드를 이용하여 필드값을 획득 (조건문 포함)
 * @author JWYoon
 *
 */
public class PrivateCollection4 {
    class PrivateCollection {
        private Collection<Object> privateCollection;
        public	Collection<Object> publicCollection;

        private Collection<Object> getCollectionInner(int x) {
            if(x > 0) return this.publicCollection;
            else return this.privateCollection;
        }

        public Collection<Object> getPublicCollection() {
            return this.publicCollection;
        }

        public Collection<Object> getCollectionMid(int x) {
            if(x > 0) return getCollectionInner(x); // @violation
            else return getPublicCollection();
        }

        public Collection<Object> getCollection(int x) {
            if(x > 0) return getCollectionMid(x); // @violation
            return getCollectionInner(x); // @violation
        }
    }
}
