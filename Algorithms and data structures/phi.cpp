int phi (int n)
{
    int result = n;
    for (int I = 2; I * I <= n; ++i)
        if (n % I == 0)
        {
            while (n % I == 0)
                n /= I;
            result -= result / I;
        }
    if (n > 1)
        result -= result / n;
    return result;
}
