int fac(int n)
{
    return (n*fac(n-1)); //@violation
}



int fac_ok(int n)
{
    if (n <= 0)
        return 1;
    else
        return (n*fac(n-1));
}