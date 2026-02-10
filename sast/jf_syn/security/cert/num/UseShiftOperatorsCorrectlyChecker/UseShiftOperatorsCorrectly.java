//checker : USE_SHIFT_OPERATORS_CORRECTLY
package security;

public class UseShiftOperatorsCorrectly {
    public void USOCC_func_001(int param1, int dump) {
        int temp = 0;
        if(true) {
            if(temp > 0 || dump < 31) {
                //dosomething
            }
        }
        temp = 1 << param1;  // @violation
    }

    public void USOCC_func_002(long param2) {
        //long if문 없는거
        long temp = 0;
        if(temp) {
            //dosomething
        }
        temp = 1 << param2;  // @violation
    }

    public void BUOISD_func_003(int param3) {
        int temp = 0;
        if(true) {
            if(temp > 0 || param3 < 31) {
                //dosomething
            }
        }
            int temp = 1 << param3;
    }

    public void BUOISD_func_004(long param4) {

        int temp = 1 << param4; // @violation

    }
}