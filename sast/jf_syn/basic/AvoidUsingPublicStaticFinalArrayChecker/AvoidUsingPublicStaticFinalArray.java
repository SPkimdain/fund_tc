package basic;

import java.util.Arrays;
import java.util.Collections;
import java.util.List;

public class AvoidUsingPublicStaticFinalArray {
    public static final String[] EMPLOYEE_NAME1 = {"John", "Smith","Ian"}; // @violation

    // First method: change public to private,
    // and add final list of public
    private static final String[] EMPLOYEE_NAME2 = {"John", "Smith", "Ian"};
    public static final List<String> EMPLOYEE_NAME_LIST = Collections.unmodifiableList(Arrays.asList(EMPLOYEE_NAME2));

    // Second method: make array private and create
    // a public method that returns a copy of the array
    private static final String[] EMPLOYEE_NAME3 = {"John", "Smith", "Ian"};
    public static final String[] getEmployeeName() {
        return EMPLOYEE_NAME3.clone();
    }
}