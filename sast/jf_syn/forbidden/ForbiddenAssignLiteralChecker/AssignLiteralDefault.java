package target.pkg.path;

public class AssignLiteralDefault
{
    private int targetFieldVar;
    public int excludedFieldVar;

    public static int targetStaticField;
    protected static int excludedStaticField;

    public void targetMethodAce(String targetParamVar) {
        targetParamVar = "a"; // @violation
        targetFieldVar = 2; // @violation
        excludedFieldVar = 3; // @violation
        targetStaticField = 2 + 3; // Not bug
    }

    public void excludedMethodAce(float targetParamVar) {
        targetParamVar = 3.0; // @violation
        targetFieldVar = 4; // @violation
        excludedStaticField = 5; // @violation
    }

    public static class ExcludedClass {

        private int innerTargetFieldVar;
        protected static int innerTargetStaticField;

        public void targetMethodFake() {
            innerTargetFieldVar = 1; // @violation
            innerTargetStaticField = 2; // @violation
        }
    }

    public static class TargetClassBase {

    }
}