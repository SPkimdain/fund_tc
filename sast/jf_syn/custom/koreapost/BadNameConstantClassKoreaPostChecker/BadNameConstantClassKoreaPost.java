package pobis.xyz.xyzaa.consts;

public class BadNameConstantClassKoreaPost {
    public interface XyzaaConstants {   // @violation
        // ...
    }

    public interface XyzaaConst {       /* SAFE */
        // ...
    }
}
