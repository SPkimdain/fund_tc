package security;

class Vector {  // @violation
    private int val = 1;
    public boolean isEmpty() {
        if (val == 1) {
            return true;
        } else {
            return false;
        }
    }
}