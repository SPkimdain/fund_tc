package custom.consts;

public class DoNotUseAnythingOtherThanConstantClassInterfaceType {
    public class XyzaaCoConst {         // @violation
        // ...
    }

    public class XyzaaCooo {            /* SAFE */
        // ...
    }

    private class XyzaaCoConst {        /* SAFE */
        // ...
    }

    public interface XyzbbCoConst {     /* SAFE */
        // ...
    }
}
