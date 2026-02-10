package hanaw.AM.ABCD.EF.so;

public class OAM1001Q00 {               // safe
    private MAM1001U00 mAM1001u00;      // @violation
    private MAM1001U00 mam1001u00;      // safe

    private void oam1001q00_a0000_b() {  // safe

    }

    private void oAM1001q00_a0000_b() {  // @violation

    }
}

public class BAM1001D00 {               // @violation
    // ...
}
