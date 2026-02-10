using System;

public class cc
{
    public static void mcc(int x)
    {
        switch (x)
        {
            case 0:
            case 1:
            case 2:
            case 3:
            case 4:
            case 5:
            case 6:
            case 7:
            case 8:
            case 9:
            case 10:
            case 11:
            case 12:
            case 13:
            case 14:
            case 15:
            case 16:
            case 17:
            case 18:
            case 19:
                break;
            default:
                Console.WriteLine("default");
                break;
        }
    }

    public int fun1(int x) // @violation
    {
        if (x == 0) return 0;
        if (x == 1) return 0;
        if (x == 2) return 0;
        if (x == 3) return 0;
        if (x == 4) return 0;
        if (x == 5) return 0;
        if (x == 6) return 0;
        if (x == 7) return 0;
        if (x == 8) return 0;
        if (x == 9) return 0;
        if (x == 10) return 0;
        if (x == 11) return 0;
        if (x == 12) return 0;
        if (x == 13) return 0;
        if (x == 14) return 0;
        if (x == 15) return 0;
        if (x == 16) return 0;
        if (x == 17) return 0;
        if (x == 18) return 0;
        if (x == 19) return 0;
        return -1;
    }

    public int fun2(int x)
    {
        if (x == 0) return 0;
        if (x == 1) return 0;
        if (x == 2) return 0;
        if (x == 3) return 0;
        if (x == 4) return 0;
        if (x == 5) return 0;
        if (x == 6) return 0;
        if (x == 7) return 0;
        if (x == 8) return 0;
        if (x == 9) return 0;
        if (x == 10) return 0;
        if (x == 11) return 0;
        if (x == 12) return 0;
        if (x == 13) return 0;
        if (x == 14) return 0;
        if (x == 15) return 0;
        if (x == 16) return 0;
        if (x == 17) return 0;
        if (x == 18) return 0;
        return -1;
    }


}