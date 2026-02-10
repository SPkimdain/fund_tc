package cc;

import java.lang.Math;

public class AccessingConstantIndexInLoop {
    public int[] a = new int[10];

    public void func(int[][] b) {
        int[] z = new int[20];
        int c;

        for (int i = 0;i < a.length;i++) {
            if (a[i] == 0) c++; // OK
        }

        for (int k = 0;k < 10;k++) {
            a[c] = b[c][k]; // @violation (a[c])
            b[k][c]++; // OK
            z[k] = a[0] + 10; // @violation (a[0])
        }

        for (int j = 0;j < z.length - 1;j++) {
            int i = ((int)(Math.random() * z.length)) % z.length;
            int temp = z[i]; // OK
            z[i] = z[j]; // OK
            z[j] = temp; // OK
            a[j] = b[0][a[0]]; // @violation 2 (a[0])
        }
    }
}
