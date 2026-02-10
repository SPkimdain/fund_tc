package nd;

class DeepPathTest {
    int global = 0;
    void testFunc() {
        String x = null;
        if(global > 1) {
            return;
        }
        if(global > 2) {
            return;
        }
        if(global > 3) {
            return;
        }
        if(global > 4) {
            return;
        }
        if(global > 5) {
            return;
        }
        if(global > 6) {
            return;
        }
        if(global > 7) {
            return;
        }
        if(global > 8) {
            return;
        }
        if(global > 9) {
            return;
        }
        if(global > 10) {
            return;
        }
        if(global > 11) {
            return;
        }
        if(global > 12) {
            return;
        }
        if(global > 13) {
            return;
        }
        if(global > 14) {
            return;
        }
        String y = null;
        y.toUpperCase(); /* BUG */
        return;
    }
}