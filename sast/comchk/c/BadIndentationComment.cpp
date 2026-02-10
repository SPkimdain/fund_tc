    /* Bug */
int test(int a) {
    int a;                  /* Safe */
    int b;              /* Bug */
    int c;                  /* Safe */
    int d;                      /* Bug */

    if (2 == a) {
        b = 2;                     /* Safe */
        return true;                    /* Bug */
    } else {
        return isPrime(a);      /* Safe */
    }

    /* Safe */
    {
        /* Safe */
        {

        }
        /* Safe */

        /* Safe */
        {
            /* Safe */
            {
                    /* Bug */
                int b;

            }
            /* Safe */
        }
    }
}
