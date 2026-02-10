package test.DoNotExterndValidationClass;

import org.apache.struts.action.*;

public class RegistrationForm extends ActionForm {  // @violation
    private String name;
    private String email;
    public RegistrationForm() {
        super();
    }
}

public class RegistrationForm2 extends DynaActionForm { // @violation
    private String name;
    private String email;
    public RegistrationForm2() {
        super();
    }
}

public class RegistrationForm3 extends org.apache.struts.action.ActionForm {    // @violation
    private String name;
    private String email;
    public RegistrationForm3() {
        super();
    }
}