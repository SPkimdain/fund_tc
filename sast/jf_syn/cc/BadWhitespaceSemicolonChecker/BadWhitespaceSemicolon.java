package cc;

public class BadWhitespaceSemicolon {

    private int field = 3;
    private int field2 = 5 ; // @violation

    public void func() {
        int a = 3;
        int b = 2
                ; // @violation
        int c = a + b ; // @violation

        a = ((b + 2) + 3) + (a + b) ; // @violation
        for(int i=0; i<20; i++) {
            b = b + 1 ; // @violation
            c++ ; // @violation
            a = a + 1 /* COMMENT */; // @violation
            b = b + 2/* COMMENT */; /* SAFE */
        }
    }

    public static class False1 {
        private static final StringBuffer _execQuery = new StringBuffer();
        static {
            // False alarm case from NH : 20140620
            _execQuery.append("DELETE /*DYNAMIC_KEYWORD*//*+'TB_LA_IS_BH_USR_MENU_EST_ED001.execute'*/ \n");
            _execQuery.append("  FROM TB_LA_IS_BH_USR_MENU_EST\n");
            _execQuery.append(" WHERE usrid            = ?     /* 사용자ID                */\n");
            _execQuery.append("   AND sra_na_menu_sqno = ?     /* 축산경제통합메뉴일련번호  */\n");
            _execQuery.append("   AND inq_hdngnm       = ?     /* 조회항목명               */\n");
        }
    }
}
