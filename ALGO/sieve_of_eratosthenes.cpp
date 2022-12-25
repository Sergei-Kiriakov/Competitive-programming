vector<bool> sieve(int n)
{
    vector<bool> prime (N+1, true);
    prime[0] = prime[1] = false;
    for (int i = 2; i * i <= n; ++i)
    {
        if (prime[i])
        {
            for (int j = i * i; j <= n; j += i)
            {
                prime[j] = false;
            }
        }
    }
    return prime;
}

// https://codeforces.com/problemset/problem/1366/D - tests