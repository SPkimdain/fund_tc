package cc;

public class DeclareAtTheBeginningOfBlock {
    int ivar1;
    int ivar2;

    public void func1(boolean condition) {
        int int1 = 0;
        int int2;
        if(condition) {
            condition = false;
            int int3 = 0;   // @violation
            // Do something ...
        }
    }

    public void func2(boolean condition) {
        if(condition) {
            int int4 = 0;
            condition = false;
            int int5 = 0;   // @violation
        }
        for(int i=0; i<10; i++) {
            // Do something ...
        }
        ArrayList<String> reportList = new ArrayList<>();     // @violation
        for(String str : reportList) {
            // Do something
        }
    }

    public void func3(boolean condition) {
        var var1 = 0;
        if (condition) {
            var var2 = 0;
            condition = false;
            var var3 = 0; // @violation
        }
    }

    public void func1(boolean condition) {
        Comparator<String> c2 = (String lhs, String rhs) -> {
            int int4 = 0;   // @violation
            condition = false;
            int int5 = 0;   // @violation
        };
    }
}
