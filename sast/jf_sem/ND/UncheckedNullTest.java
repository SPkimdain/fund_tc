package nd;

/**
 * Writer: Gyuhang Shim
 * Date: 7/3/12
 */
public class UncheckedNullTest {

    /*
    public static IntegerToStringConverter fromShort(NumberFormat numberFormat,
                                                     boolean primitive) {
        return new IntegerToStringConverter(numberFormat,
                primitive ? Short.TYPE : Short.class, Short.class);
    }

    private IntegerToStringConverter(NumberFormat numberFormat, Class fromType,
			Class boxedType) {
		super(fromType, String.class);
		this.primitive = fromType.isPrimitive();
		this.numberFormat = numberFormat;
		this.boxedType = boxedType;
	}
    */
    public void test1(boolean flag) {
        boolean test = flag ? foo(Short.TYPE) : foo(Short.class);
    }
    public boolean foo(Class clazz) {
        return clazz.isPrimitive();
    }
    public static boolean isEmpty(String a) {
        return a == null || a.equals("");
    }
    public String test2(String s) {
        return isEmpty(s) ? "" : s.toLowerCase(); /* SAFE */
    }
}
