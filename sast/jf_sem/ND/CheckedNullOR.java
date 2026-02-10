package nd;

class CheckedNullOR {
    boolean isEmpty(String str){
        return str == null || str.length()==0;
    }
    String foo (String str){
        if (isEmpty(str)
                || str.indexOf("a")==1) { /* SAFE */
            return str;
        }
        return str;
    }
}