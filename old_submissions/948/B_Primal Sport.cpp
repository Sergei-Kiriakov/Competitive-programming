//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("avx,avx2,fma")

#include <bits/stdc++.h>

#include <random>

#define int long long
#define double long double
#define endl "\n"
#define all(x) (x).begin(), (x).end()

using namespace std;

const int mod = 1e9 + 93, big = 2e6;

void solve()
{
    int x;
    cin >> x;
    vector<bool> prime(x + 1, true);
    prime[0] = prime[1] = false;
    for (int i = 2; i <= x; ++i)
        if (prime[i])
            if (i * i <= x)
                for (int j = i * i; j <= x; j += i)
                    prime[j] = false;
    int d = 1;
    int min1 = 1e9;
    int x1 = x;
    for (int i = 2; i * i <= x1; ++i)
    {
        while (x1 % i == 0)
        {
            x1 /= i;
            min1 = min(min1, (x - 1) / i * i + 1);
        }
    }
    if (x1 != 1)
    {
        min1 = min(min1, (x - 1) / x1 * x1 + 1);
    }
    int min2 = 1e9;
    for (int xx = min1; xx <= x; ++xx)
    {
        int xx1 = xx;
        for (int i = 2; i * i <= xx1; ++i)
        {
            while (xx1 % i == 0)
            {
                xx1 /= i;
                min2 = min(min2, (xx - 1) / i * i + 1);
            }
        }
        if (xx1 != 1 and xx1 != xx)
        {
            min2 = min(min2, (xx - 1) / xx1 * xx1 + 1);
        }
    }
    cout << min2 << endl;
}

int32_t main()
{
//  ofstream cout("sum.out");
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cout << fixed;
    cout.precision(7);
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    int tt = 1;
//    cin >> tt;
    while(tt-->0)
    {
        solve();
    }
}


/*
*/