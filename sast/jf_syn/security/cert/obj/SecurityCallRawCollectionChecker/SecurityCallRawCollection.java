import java.util.List;

class SecurityCallRawCollection {

    private static void addToList(List list, Object obj) {
        list.add(obj);      // @violation
    }

    public static void main(String[] args) {
        List<String> list = new ArrayList<String> ();
		Map map = new Map();	// @violation
		Set set = new Set();		// @violation
        addToList(list, 42);
        System.out.println(list.get(0)); // Throws ClassCastException
    }
}