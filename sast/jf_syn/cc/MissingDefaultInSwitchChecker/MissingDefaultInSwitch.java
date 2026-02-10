package cc;

class MissingDefaultInSwitch {

    public enum DialogType {
        SAVE, SAVEAS, OPEN, PDF;
    }
    public void test(int a, int b, DialogType type) {
    //public void test(int a, int b) {
        switch (a) {   		 	/* Safe */
        case 1:
            switch (b) {    // @violation
            case 2:
                //Do something
                break;
            }
            break;
        default:
            //Do something
            break;
        }
        switch (b) {   		 		// @violation
        case 1:
            //Do something
            break;
        }

        switch (type) {
            case SAVE:
            case SAVEAS:
                int x = 1;
                break;
            case OPEN:
                int y = 1;
                break;
            case PDF:
                int z = 1;
                break;
            default:
                break;
        }
    }

    public double test2(Object obj) {
        return switch (obj) { // @violation
            case Integer i -> i.doubleValue();
            case Float f -> f.doubleValue();
            case String s -> Double.parseDouble(s);
//            default -> 0d;
        };
    }

    public double test3(Object obj) {
        return switch (obj) {
            case Integer i -> i.doubleValue();
            case Float f -> f.doubleValue();
            case String s -> Double.parseDouble(s);
            default -> 0d;
        };
    }
}