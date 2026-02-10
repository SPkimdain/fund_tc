package nd;

import java.lang.String;

/* OPT : -show_followers */
class PruningWithStringEquals {
    void XXXContext (){
        String field = null;
        String key = "XXX";

        if (key.equals("XXX")) {
            field.length(); /* BUG */
        } else if (key.equals("YYY")){
            field.length();
        } else {
            field.length();
        }
    }
    void YYYContext (){
        String field = null;
        String key = "YYY";

        if (key.equals("XXX")) {
            field.length();
        } else if (key.equals("YYY")){
            field.length(); /* BUG */
        } else {
            field.length();
        }
    }
    void ElseContext (){
        String field = null;
        String key = "ZZZ";

        if (key.equals("XXX")) {
            field.length();
        } else if (key.equals("YYY")){
            field.length();
        } else {
            field.length(); /* BUG */
        }
    }
}



