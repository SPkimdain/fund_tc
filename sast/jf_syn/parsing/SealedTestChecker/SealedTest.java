public sealed interface CarBrand permits Hyundai, Kia {}  // @violation

public final class Hyundai implements CarBrand {}
public non-sealed class Kia implements CarBrand {}