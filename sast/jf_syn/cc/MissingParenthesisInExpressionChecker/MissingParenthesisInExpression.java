package cc;

public class MissingParenthesisInExpression {
    public void func(int a, int b) {
        if((a == 0) && (b == 0)) {
            // Do something ...
        }

        if(a == 0 && b == 0) { // @violation
            // Do something ...
        }

        if(((a = (b + 1)) == 0) && (b > a)) {
            // Do something ...
        }

        if((a = b + 1) == 0 && (b > a)) { // @violation
            // Do something ...
        }

        if((a == 0 || b == 0 ) && (b == 0)) { // @violation
            // Do something ...
        }



        Runnable runner2;
        Runnable runner;

        //comment
        runner2 = new Runnable() {

            /**
             * Runnalble 무명 함수
             */

            @Override
            public void run() {
                return;
            }
        };

        //comment
        runner = new Runnable() {

            /**
             * Runnalble 무명 함수
             */

            @Override
            public void run() {
                a = 5;

                if (a == b && a>=b && a>=b) {   // @violation
                    return;
                    //return
                }
                else if(a == 0 && b == 0) { // @violation
                    return;
                    //return
                }
                else {
                    return;
                    //return
                }

                return;
            }
        };
        runner = new Runnable() {

            /**
             * Runnalble 무명 함수
             */

            @Override
            public void run() {
                a = 5;

                if (a == b) {
                    return;
                    //return
                }
                else if (a != b) {
                    return;
                    //return
                }
                else {
                    return;
                    //return
                }

                return;
            }
        };


        return;
    }
}