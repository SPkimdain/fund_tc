package src.test.java.pmd;

public class DoNotUseFloatForLoopIndices {
    public static void main(String[] args) {
        final int START = 2000000000;
        int count = 0;
        float f1 = 0;

        for(f1 = START; f1 < START + 50 ; f1++) // @violation
            count++;

        for (float f2 = START; f2 < START + 50; f2++) // @violation
            count++;

        for (double f3 = START; f3 < START + 50; f3++)
            count++;

        for (int i = START; i < START + 50; i++)
            count++;
    }
}