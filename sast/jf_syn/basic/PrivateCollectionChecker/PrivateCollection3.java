package test.com.fasoo.javafinch.syn.rule.basic.privatecollection;

import java.util.Collection;

/**
 * PRIVATE_COLLECTION Test case 3 : Complex return statements
 * 복잡한 반환 구문 (조건문, 3항 연산자 포함)
 * @author JWYoon
 *
 */
public class PrivateCollection3 {
    class PrivateCollection {
        private Collection<Object> privateCollection;
        public	Collection<Object> publicCollection;

        private Collection<Object> nullMethod(Collection<Object> o) {
            return null;
        }

        public Collection<Object> getCollection(int x) {
            if(x > 10)
                return this.privateCollection; // @violation
            else if(x > 5)
                return this.publicCollection; // Not bug
            else
                return (this.privateCollection == null) ?
                        this.publicCollection : nullMethod(this.privateCollection); // Not bug
        }

        public boolean isSame() {
            return this.privateCollection == this.publicCollection; // Not bug
        }
    }
}
