public class LambdaTestCode {
    public void LambdaTestFunction1() {
        Runnable r2 = () -> System.out.println("Hello world!!");     // @violation
        r2.run();

        //(ex2)
        // 1번 표현식 한개
        Comparator<String> c1 = (String lhs, String rhs) -> lhs.compareTo(rhs);  // @violation
        int result1 = c1.compare("Hello", "World");

        // 2번 표현식 두개
        Comparator<String> c2 = (String lhs, String rhs) -> {    // @violation
            System.out.println("Comparing "+ lhs + " and " + rhs);
            return lhs.compareTo(rhs);
        };
        int result2 = c2.compare("Hello","World");

        //3번 타입 추론
        Comparator<String> c3 = (lhs, rhs) -> lhs.compareTo(rhs);    // @violation
        int result3 = c3.compare("Hello", "World");
    }

    //(ex3)
    @FunctionalInterface
    interface Square {
        public int run(int number);
    }

    public void LambdaTestFunction2() {
        int number = 10;
        Square s = (num) -> num*num;     // @violation
        int squaredNum = s.run(number);
    }
}