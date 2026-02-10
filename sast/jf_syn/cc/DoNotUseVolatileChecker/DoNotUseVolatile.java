package cc;

import java.lang.String;

public class DoNotUseVolatile {
    public String gNonVolatile;
    public volatile String gVolatile; // @violation
}
