public class depth {

    public int depth(int x) { // @violation
        if (x > 0) {
            if (x > 1) {
                if (x > 2) {
                    if (x > 3) {
                        if (x > 4) {
                            if (x > 5) {
                                return -1;
                            }
                        }
                    }
                }
            }
        }
        return 0;
    }


    public int depth2(int x) {
        if (x > 0) {
            if (x > 1) {
                if (x > 2) {
                    if (x > 3) {
                        if (x > 4) {
                            return -1;
                        }
                    }
                }
            }
        }
        return 0;
    }

}
