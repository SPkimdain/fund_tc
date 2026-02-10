package cc;

public class MissingBlockInControlStatement {
    public void test(int x, int y, int z) {
        if (x > y) {
            // good
        } else {
            // good
        }

        if (x < y) return; // @violation

        if (x == y) {

        } else z = 1; // @violation

        if (x == z) x++; // @violation
        else y++; // @violation

        if (z > 0) z--; // @violation

        while (x > z) x--; // @violation

        while (x < z) {
            x++; // good
        }

        for (int i = 0;i < z; i++) System.out.println(z); // @violation

        for (int i = 0;i < z; i++) {
            System.out.println(i); // good
        }

        do x++; while(x < y); // @violation

        do {
            x++; // good
        } while (x < y);

        switch (x) {
            case 0:
            case 1:
                x++;
                y++;
                z++;
                break;
            case 2:
                break;
            case 3: {
                break; // good
            }
            default:
                break;
        }

        if(x == y) {
            // good
        } else if(x < y) return; // @violation

        if(x == y) {
            // good
        } else if(x < y) {
            // good
        }
    }
}