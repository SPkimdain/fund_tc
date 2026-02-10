package cc;

public class ForbiddenPropertyMethod {
    public class SetPropertyBad1 {
        void func() {
            String Id = "Id";
            String name = "id";

            System.setProperty(s1, s2);     // @violation
        }
    }
}