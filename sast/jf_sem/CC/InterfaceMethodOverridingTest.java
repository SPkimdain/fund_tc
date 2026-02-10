package cc;

/**
 * User: starblood
 * Date: 5/24/13
 * Time: 1:25 PM
 * 우리 투자 증권에서 보고 되었던 INFINITE_RECURSIVE_CALL 이 클래스의 이름에서 발생하는 현상을 재현하고자 작성된 테스트 케이스
 *
 * 문제의 원인은 특정 메소드를 구현해야 하는 interface 를 상속받는 클래스가 해당 메소드를 overriding 할 때, byte code 에서 똑같은
 * 이름의 메소드가 하나 더 추가 된다. 이 메소드에서 overriding 하는 메소드를 호출하면서 허위 경보가 발생한다.
 *
 * 아래 코드는 이 클래스의 byte code 를 나타낸다.
 *
 * public BugTest();
        flags: ACC_PUBLIC
        Code:
        stack=1, locals=1, args_size=1
        0: aload_0
        1: invokespecial #1                  // Method java/lang/Object."<init>":()V
        4: return
        LineNumberTable:
        line 6: 0

        public PersInfoVO getModel();
        flags: ACC_PUBLIC
        Code:
        stack=1, locals=1, args_size=1
        0: aload_0
        1: getfield      #2                  // Field vo:LPersInfoVO;
        4: areturn
        LineNumberTable:
        line 12: 0

        public java.lang.Object getModel();
        flags: ACC_PUBLIC, ACC_BRIDGE, ACC_SYNTHETIC
        Code:
        stack=1, locals=1, args_size=1
        0: aload_0
        1: invokevirtual #3                  // Method getModel:()LPersInfoVO;
        4: areturn
        LineNumberTable:
        line 6: 0
    }

    Interface 의 method 를, implement 하는 method 에서 infinite recursive call 이 나타나지 않는 것을 테스트
 */
public class InterfaceMethodOverridingTest implements ModelDriven<PersInfoVO> {

    private PersInfoVO vo;

    public PersInfoVO getModel() {
        return vo;
    }
}

interface ModelDriven<T> {
    public T getModel();
}

class PersInfoVO {

}