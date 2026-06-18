//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("avx,avx2,fma")

#include <bits/stdc++.h>

#define int long long
//#define double long double
#define endl "\n"
#define all(x) (x).begin(), (x).end()

using namespace std;

constexpr int mod = 998244353, mod2 = 1e9 + 9;

const int N = 2e6;
vector<int> fact(N + 1, 1), in_fact(N + 1, 1);

int bin_pow (int a, int n)
{
    int ans = 1;
    while (n)
    {
        if (n & 1)
            ans = a * ans % mod;
        n >>= 1;
        a = a * a % mod;
    }
    return ans;
}

int inverse_mod(int n)
{
    return bin_pow(n, mod - 2);
}

int cnk (int n, int k)
{
    if (n < 0)
        return 0;
    if (k > n)
        return 0;
    return fact[n] * in_fact[k] % mod * in_fact[n - k] % mod;
}

void solve ()
{
    int l, n;
    cin >> l >> n;
    int fr = l - 2 * n;
    int ans = 0;
    for (int i = 0; i <= fr; i += 2)
    {
        int cnt = i / 2;
        ans = (ans + cnk(n - 1 + cnt, n - 1) * cnk(l - n - i, n) * 2) % mod;
    }
//    cout << 2 * cnk(l, 2 * n) << endl;
    cout << (mod + 2 * cnk(l, 2 * n) - ans) % mod << endl;
}

int32_t main()
{
//    ofstream cout("std.out");
//    ifstream cin("std.in");
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cout << fixed;
//    cout.precision(7);
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

    for (int i = 2; i <= N; ++i)
        fact[i] = fact[i - 1] * i % mod;
    in_fact[N] = inverse_mod(fact[N]);
    for (int i = N - 1; i > 0; --i)
        in_fact[i] = in_fact[i + 1] * (i + 1) % mod;

    int tt = 1;
    cin >> tt;
    while(tt-->0)
    {
        solve();
    }
}


/*
*/