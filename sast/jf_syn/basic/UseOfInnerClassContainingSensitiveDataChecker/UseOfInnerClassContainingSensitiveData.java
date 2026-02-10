package basic;
// USE_OF_INNER_CLASS_CONTAINING_SENSITIVE_DATA Test Case
public class UseOfInnerClassContainingSensitiveData {
    private String ownerMemberOne, ownerMemberTwo;
    private final long a = 0;
    private float aa = 0;

    public UseOfInnerClassContainingSensitiveData(String varOne, String varTwo) {
        this.ownerMemberOne = varOne;
        this.ownerMemberTwo = varTwo;
        float aaa = aa%2;
    }

    public class InnerClassPublic {
        private String innerMemberOne;
        private String ownerMemberOne;

        public InnerClassPublic(String innerVarOne) {
            this.innerMemberOne = innerVarOne;
            if(innerMemberOne.equals(ownerMemberTwo)) { // @violation
                System.out.println("true");
                ownerMemberOne = UseOfInnerClassContainingSensitiveData.this.ownerMemberOne; // @violation
                this.innerMemberOne = ownerMemberTwo; // @violation
                UseOfInnerClassContainingSensitiveData.this.ownerMemberOne = this.innerMemberOne; // @violation
            }
        }

        public String concat(String separator) {
            System.out.println(((a%1) + (aa*1))); // @violation
            System.out.println("Value of memberOne is: " + ownerMemberOne + ", memberTow is: " + ownerMemberTwo); // @violation
            if(ownerMemberOne == null || ownerMemberOne.length() == 0) {
                System.out.println("ownerMemberOne null");
            }
            if(null == ownerMemberTwo || 0 == ownerMemberTwo.length()) { // @violation 2
                System.out.println("ownerMemberTwo null");
            }
            return UseOfInnerClassContainingSensitiveData.this.ownerMemberTwo + separator + this.innerMemberOne; // @violation
        }

        public class InnerClassPublic2 {
            private String member1, member2;

            public InnerClassPublic2() {
                member1 = ownerMemberOne; // @violation
                member2 = ownerMemberTwo; // @violation

                new AbstractClass() {
                    @Override
                    public void test() {
                        if(null == ownerMemberTwo || 0 == ownerMemberTwo.length()) { // @violation 2
                            System.out.println("ownerMemberTwo null");
                        }
                        ownerMemberTwo = "test"; // @violation
                        System.out.println("member1 : " + member1 + ", member2 : " + member2);
                    }
                }.test();
            }
        }
    }

    public class InnerClassPublic2{
        private String member1, member2;

        public InnerClassPublic2() {
            this.member1=ownerMemberOne; // @violation
            ownerMemberTwo="test"; // @violation
        }
    }
}

abstract class AbstractClass {
    String ownerMemberOne, ownerMemberTwo;
    public abstract void test();

    public class InnerClassPublic2{
        private String member;

        public InnerClassPublic2(String member) {
            this.member=ownerMemberOne; // @violation
            ownerMemberTwo=member; // @violation
        }
    }
}

public class BaseTestClass {
//    private static String TEST = "test";
    public String ownerMemberOne;
//    private String ownerMemberOne;

    public Runnable tempString = new Runnable() {
        @Override
        public void run() {

        }

        @Override
        public boolean equals(Object obj) {
            return super.equals(obj);
        }
    };

    public void onReceive(int a, int b) {

    }

    public class BaseDerievedTestClass  {
        @Override
        public void onReceive(int a, int b) {
            super.onReceive(a, b);
            if (a == b ) {
                try {
//                    tempString.equals(String.valueOf(tempString));
//                    tempString.equals(String.valueOf(TEST));
//                    tempString.equals(String.valueOf(TEST));
                    tempString.equals(String.valueOf(ownerMemberOne));
                    tempString.run();
                }
                catch (Exception e) {

                }
            }
        }
    };
}
