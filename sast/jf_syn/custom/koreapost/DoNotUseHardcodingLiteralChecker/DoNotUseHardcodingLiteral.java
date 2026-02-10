package custom;

class DoNotUseHardcodingLiteral {
    public static final String test001 = "123456789";
    public static final String test002 = "1234567890";
    private static final String test003 = "1234567890";             // @violation
    public final String test004 = "1234567890";                     // @violation
    public String test005 = "1234567890";                           // @violation

    class StringField {
        String f = "1111111111111111";                              // @violation
        String A = "0000011111";
        String B = "1123981239";                                    // @violation
    }

    public static void main(String[] args) {
        String test01 = "12345678";
        String test02 = "123456789";                                // @violation

        String test03 = "1234567890";                               // @violation
        String test04 = "1234a56789";
        String test05 = "1234 56789";
        String test06 = "1234_56789";

        String test07 = "ab1234567";                                // @violation
        String test08 = "1234ab567";
        String test09 = "1234567ab";

        String test10 = "ab123456";
        String test11 = "abc1234567";
        String test12 = "ab12345678";

        String test13 = "a";
        String test14 = "abcdefgh";
        String test15 = "abcdefghi";
        test15 = "1234567890";                                      // @violation

        char test16 = 'a';
        int test17 = 123456789;

        Test test = new Test() {
            private static final String test003 = "1234567890";     // @violation

            public void test1() {
                String test01 = "ab1234567";                        // @violation

                IDataSet data = new IDataSet();
                data.put("ab1234567", record.getString("ab1234567"));
            }
        };

        Test test = new Test("1234567890");
        Test test = getTest("1234567890");
        Test test = () -> {
            String str1 = "12345678999";                            // @violation
            return str1;
        };
        Test test = () -> {                                         // @violation
            return "12345678999";
        };

        String[] test = {"1234567890", "1234567891"};               // @violation
        test[0] = "1234567890";                                     // @violation
    }
}