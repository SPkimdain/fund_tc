public class GuardedPatternTest {
    public double test1(Object obj) {
        return switch (obj) {
            case String s && s.length() > 0 -> Double.parseDouble(s); // @violation
            default -> 0d;
        };
    }

    public double test2(Object obj) {
        return switch (obj) {
            case String s && s.length() > 0 && !(s.contains("#") || s.contains("@")) -> Double.parseDouble(s); // @violation
            default -> 0d;
        };
    }

    public double test3(Object obj) {
        return switch (obj) {
            case String s when s.length() > 0 -> Double.parseDouble(s); // @violation
            default -> 0d;
        };
    }
}