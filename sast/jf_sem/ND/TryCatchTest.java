package nd;

/**
 * Writer: Gyuhang Shim
 * Date: 6/27/12
 */
// TODO : 아래 케이스는 ND 를 검출 하지 못한다. 검출 하도록 수정 필요
public class TryCatchTest {
    public String getString() {
        try {
            return Object.class.getName();
        } catch (Exception e) {

        }
        return null;
    }
    public void getStringTest() {
        getString().toLowerCase();
    }
}
