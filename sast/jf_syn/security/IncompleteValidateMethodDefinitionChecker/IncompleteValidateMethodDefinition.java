import java.lang.*;
import org.apache.struts.*;

public class RegistrationForm1 extends org.apache.struts.validator.ValidatorForm {
    private String name;
    private String email;

    public RegistrationForm() {
        super();
    }

    public ActionErrors validate(ActionMapping mapping, HttpServletRequest request) {   // @violation
        ActionErrors errors = new ActionErrors();
        if (getName() == null || getName().length() < 1) {
            errors.add("name", new ActionMessage("error.name.required"));
        }
        return errors;
    }
}

public class RegistrationForm2 extends org.apache.struts.validator.ValidatorForm {     // @violation
    private String name;
    private String email;

    public RegistrationForm() {
        super();
    }

    public ActionErrors validate1(ActionMapping mapping, HttpServletRequest request) {
        ActionErrors errors = new ActionErrors();
        if (getName() == null || getName().length() < 1) {
            errors.add("name", new ActionMessage("error.name.required"));
        }
        return errors;
    }
}

public class RegistrationForm3 extends org.apache.struts.validator.ValidatorForm {
    private String name;
    private String email;

    public RegistrationForm() {
        super();
    }

    public ActionErrors validate(ActionMapping mapping, HttpServletRequest request) {
        ActionErrors errors = super.validate(mapping, request); /* SAFE */
        if (getName() == null || getName().length() < 1) {
            errors.add("name", new ActionMessage("error.name.required"));
        }
        return errors;
    }
}