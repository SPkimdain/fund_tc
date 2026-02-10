package basic;

import java.io.ObjectStreamField;
import java.io.Serializable;
import java.util.List;

/**
 * Writer: Gyuhang Shim
 * Date: 4/9/12
 */
public class IncorrectSerialPersistentFieldsModifier implements Serializable {
    public ObjectStreamField[] serialPersistentFields = {new ObjectStreamField("myField", List.class)}; // @violation

    private static final int [] test = {1,2,3};
    public void doSomething() {}
}
