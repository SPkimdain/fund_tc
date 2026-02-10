public class SwitchTestCode {
    public double test2(Object obj) {
        return switch (obj) {
            case Integer i -> i.doubleValue();  // @violation
            case Float f -> f.doubleValue();    // @violation
            case String s -> Double.parseDouble(s); // @violation
            default -> 0d;
        };
    }
}