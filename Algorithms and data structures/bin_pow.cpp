int bin_pow (int a, int n)
{
    int ans = 1;
    while (n)
    {
        if (n & 1)
            ans = ans * a;
        a = a * a;
        n >>= 1;
    }
    return ans;
}
