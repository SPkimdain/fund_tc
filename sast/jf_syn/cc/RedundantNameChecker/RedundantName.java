package cc;

public class RedundantName {

    public int var;

    public enum Enum {
        ENUM_1, ENUM_2, ENUM_3;
        private int var; // @violation
    };

    public void func(int var) { // @violation

        int var; // @violation
        int local;

        for(int var=0; var<10; var++) { // @violation
            int local = 0; // @violation
            int k;
            {
                {
                    int k = 0; // @violation
                    int v = 0;
                }
                int local = 2; // @violation
                int k = local; // @violation
                int v = 0;
            }
        }
    }

    public RedundantName() {
        int var = 0; // @violation
        // Do something ...
    }

    static {
        int var = 0; // @violation
        int k;
        {
            int k; // @violation
        }
    }

    int lambda1 = (int var) -> var;  // @violation

    int lambda2 = () -> {
        int var;    // @violation
        return var;
    };
}
