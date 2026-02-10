// INDENTATION.METHOD
package cc;

public class BadIndentationMethod {

    private void method1() { 		/* Safe */

    }

		private void method2() { 		// @violation

		}

    //test
    private void method3() { 		/* Safe */

    }
    //test
    private void method4() { 		// @violation

    }
    @Override
    private void method5() { 		// @violation

    }

    @Override
    private void method6() { 		/* Safe */

    }

    int a = 0;

    private void method7() { 		/* Safe */

    }

    class test {
        int b = 0;
    }

    private void method8() { 		/* Safe */

    }

}
