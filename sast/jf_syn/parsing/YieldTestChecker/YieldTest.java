public class YieldTest {
    public String test1(Object obj) {
        return switch (day) {
            case MONDAY, FRIDAY, SUNDAY -> 6;
            case TUESDAY -> 7;
            default -> {
                String s = day.toString();
                int result = s.length();
                yield result; // @violation
            }
        };
    }
}