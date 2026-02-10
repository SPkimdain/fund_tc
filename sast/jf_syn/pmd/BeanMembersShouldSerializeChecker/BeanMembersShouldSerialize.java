package src.test.java.pmd;

import java.io.Serializable;
import lombok.Getter;
import lombok.Setter;
import lombok.Data;

@Documented
@NoArgsConstructor
@Getter
public class BeanMembersShouldSerialize implements Serializable { // @violation
    private transient int someFoo;
    private static int otherFoo;
    private int moreFoo;
    @Getter
    private int badFoo;

    private void setMoreFoo(int moreFoo) {
        this.moreFoo = moreFoo;
    }

    private int getMoreFoo() {
        return this.moreFoo;
    }
}