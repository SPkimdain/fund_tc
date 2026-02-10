package test.com.fasoo.javafinch.syn.rule.basic.privatecollection;

import java.util.Collection;

/**
 * PRIVATE_COLLECTION Test case 5 : Collection & single variable mixed
 * Collection에 대해서만 오류 검출 여부 확인
 * @author JWYoon
 *
 */
public class PrivateCollection5 {
    class PrivateCollection {
        private Collection<Object> privateCollection;
        private Object privateObject;

        public Collection<Object> getCollection() {
            return this.privateCollection; // @violation
        }

        public Object getObject() {
            return this.privateObject; // Not bug
        }
    }
}
