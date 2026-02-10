package cc;

public class BadCommentMod {
    public void test1() {
        /* @violation */ // MOD_START_2015-05-10_Nick_Fix_Bug_1020
        // ...
        /* @violation */ // MOD_END
    }

    public void test2() {
        // MOD_START_2015-05-11_Nick_Fix_Bug_1020
        // ...
        // MOD_END_2015-05-11
    }
}
