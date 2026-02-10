package test.com.fasoo.javafinch.syn.rule.basic.privatecollection;

import java.util.Collection;

/**
 * PRIVATE_COLLECTION Test case 1 : Simple PRIVATE_COLLECTION
 * 기본적인 PRIVATE_COLLECTION 오류 검출
 * @author JWYoon
 *
 */
public class PrivateCollection1 {
    class PrivateCollection {
        private Collection<Object> privateCollection;

        public Collection<Object> getCollection() {
            return this.privateCollection; // @violation
        }
    }
}
