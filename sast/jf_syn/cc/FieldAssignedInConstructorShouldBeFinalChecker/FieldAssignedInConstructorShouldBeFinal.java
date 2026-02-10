package field.ImmutableField;

public class FieldAssignedInConstructorShouldBeFinal {
    public class Bad1 {
        private int x;
        private int y;
        public Bad1(int y) {
            x = 7;          // @violation
            this.y = y;     // @violation
        }
        public void foo() {
            int a = x + 2;
        }
    }

    public class Good1 {
        private final int x;
        private final int y;
        public Good1(int y) {
            x = 7; /* complaint */
            this.y = y; /* compliant */
        }
        public void foo() {
            int a = x + 2;
        }
    }
}
