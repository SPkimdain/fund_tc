strictfp class SecurityCastFloatDouble {
    public static int subFloatFromInt(int op1, float op2) {
        return op1 - (int) op2;                 // @violation
    }

    public static long subFloatFromLong(int op1, float op2) {
        return op1 - (long) op2;                 // @violation
    }

    public static int subFloatFromInt(int op1, double op2) {
        return op1 - (int) op2;                 /* Safe */
    }

    public static long subDoubleFromLong(int op1, double op2) {
        return op1 - (long) op2;                 // @violation
    }

//    float 형 변수를 int 또는 long 형으로
//    double 형 변수를 long 형
    Comparator<Long> subFloatFromInt = (int op1, float op2) -> op1 - (int) op2;  // @violation
    Comparator<Long> subFloatFromLong = (int op1, float op2) -> op1 - (long) op2;  // @violation
    Comparator<Integer> subDoubleFromInt = (int op1, double op2) -> op1 - (int) op2; /* SAFE */
    Comparator<Long> subDoubleFromlong = (int op1, double op2) -> op1 - (long) op2; // @violation

    Comparator<String> c3 = (int op1) -> {
        float op2 = 3;

        int op3 = op1 - (int) op2;      // @violation
        return op3;
    };

    Comparator<String> c2 = (int op1, float op2) -> {
        int op3 = op1 - (int) op2;      // @violation
        return op3;
    };

    public static void main(String[] args) {
        int result = subFloatFromInt(1234567890, 1234567890);
        long result_long = subFloatFromLong(1234567890, 1234567890);
        long result_long_2 = subDoubleFromLong(1234567890, 1234567890);
        // This prints -46, and not 0 as may be expected
        System.out.println(result);
    }
}