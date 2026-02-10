//checker BAD_USE_SHIFT_OPERATORS_IN_SAME_DATA
package security;

public class BadUseShiftOperatorsInSameData {
    public void BUOISD_func_001() {
        int x = 10;
        x += (x<<2) + 1;    // @violation
    }

    public void BUOISD_func_002() {
        int x = 20;
        int y = x<<2;
        x += y + 1;     // @violation
    }

    public void BUOISD_func_003() {
        int x = 30;

        if (x > 0) {
            int y = x << 2;
            x += y + 1;     // @violation
        }
    }

    public void BUOISD_func_004(int param) {
        if (param > 0) {
            int x = 40;
            int y = x << 2;
            x += y + 1;     // @violation
        }
        int x = 401;
    }
}