package cc;

public class BadArrayDeclaration {
    public int[] gArray1;
    public int gArray2[]; // @violation
    public int [] gArray3; // @violation
    public int[][] gArray4;
    public int[] gArray5[]; // @violation

    public void func(int[] pArray1,
                     int pArray2[], // @violation
                     int [] pArray3, // @violation
                     int[][] pArray4,
                     int[] pArray5[]) { // @violation
        int[] lArray1;
        int lArray2[]; // @violation
        int [] lArray3; // @violation
        int[][] lArray4;
        int[] lArray5[]; // @violation
    }

    /* 특정 class type 으로 선언된 배열에 대해서 검사 수행 */
    public void test_clazzNameAsArrayType1_bugFound() {
        CustomClazz clazz[] = new CustomClazz[10]; // @violation
    }

    public void test_clazzNameAsArrayType2_bugFound() {
        CustomClazz [] clazz = new CustomClazz[10]; // @violation
    }

    public void test_clazzNameAsArrayType3_bugFound() {
        CustomClazz[] clazz[]; // @violation
    }

    public void test_clazzNameAsArrayTypeAsMethodParam1_bugFound(CustomClazz clazz[]) { // @violation

    }

    public void test_clazzNameAsArrayTypeAsMethodParam2_bugFound(CustomClazz [] clazz) { // @violation

    }

    public void test_clazzNameAsArrayTypeAsMethodParam2_bugFound(CustomClazz[] clazz[]) { // @violation

    }

    public void test_ClazzNameAsArrayType_bugNotFound() {
        CustomClazz[] clazz = new CustomClazz[10]; /* SAFE */
    }

    public CustomClazz fieldClazz1[]; // @violation
    public CustomClazz [] fieldClazz2; // @violation
    public CustomClazz[] fieldClazz3[]; // @violation

    public CustomClazz[] fieldClazz; /* SAFE */

    class CustomClazz {
        public void foo() {

        }
    }

    /**
     * False alarm case from Spring framework
     * Since 20130212
     */
    private static int[] computeLvtSlotIndices(boolean isStatic, Type[] paramTypes) {
        int[] lvtIndex = new int[paramTypes.length];
        int nextIndex = (isStatic ? 0 : 1);
        for (int i = 0; i < paramTypes.length; i++) {
            return lvtIndex;
        }
    }


    Supplier<CustomClazz[]> lambdaFunc1 = () -> {
        CustomClazz clazz[] = new CustomClazz[10];  // @violation
        return clazz;
    };

    Supplier<CustomClazz[]> lambdaFunc2 = () -> {
        CustomClazz [] clazz = new CustomClazz[10]; // @violation
        return clazz;
    };

    Supplier<CustomClazz[]> lambdaFunc3 = () -> {
        CustomClazz[] clazz[]; // @violation
        return clazz;
    };

    Supplier<CustomClazz[]> lambdaFunc4 = () -> {
        CustomClazz[] clazz = new CustomClazz[10]; /* SAFE */
        return clazz;
    };

    Consumer<String> lambdaFunc5 = (CustomClazz clazz[]) -> {   // @violation

    };

    Consumer<String> lambdaFunc6 = (CustomClazz [] clazz) -> {   // @violation

    };

    Consumer<String> lambdaFunc7 = (CustomClazz[] clazz[]) -> {   // @violation

    };

    Consumer<String> lambdaFunc8 = (CustomClazz[] clazz) -> {   /* SAFE */

    };

    public void test_ClazzNameAsArrayType_bugNotFound() {
        CustomClazz[] clazz = new CustomClazz[10]; /* SAFE */
    }
    public CustomClazz[] clazz;
}
