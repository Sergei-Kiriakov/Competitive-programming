//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("avx,avx2,fma")

#include <bits/stdc++.h>

#define int long long
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define remin(x, y) x = min(x, y)
#define remax(x, y) x = max(x, y)
#define lowpos(a, x) int(lower_bound(a.begin(), a.end(), x) - a.begin())
#define uppos(a, x) int(upper_bound(a.begin(), a.end(), x) - a.begin())

using namespace std;

constexpr int mod = 1e9 + 7;

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


void solve()
{
    int n, k;
    cin >> n >> k;
    vector<vector<int> > a(k, vector<int>(2));
    for (int i = 0; i < k; ++i)
    {
        cin >> a[i][0] >> a[i][1];
        if (a[i][0] != a[i][1])
            --n;
        --n;
    }
    if (n == 0)
    {
        cout << 1 << endl;
        return;
    }
    vector<int> dp(n + 1, 0);
    dp[0] = 1;
    for (int i = 2; i < n + 1; ++i)
    {
        int d2 = (n - (i - 2));
        int m2 = (mod + d2 * d2 - d2) % mod;
        dp[i] = dp[i - 2] * m2 % mod;
    }
    int ans = 0;
    for (int i = 0; i < n + 1; i += 2)
    {
        dp[i] = dp[i] * in_fact[i / 2] % mod;
        ans = (ans + dp[i]) % mod;
    }
    cout << ans << endl;
}

int32_t main()
{
//    ofstream cout("std.out");
//    ifstream cin("std.in");
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cout << fixed;
    cout.precision(7);
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
 * int d1 = (n - (i - 1)), d2 = (n - (i - 2));
            int m1 = d1 % mod, m2 = (mod + d2 * d2 - d2) % mod;
            dp[i] = (dp[i - 1] * m1 + dp[i - 2] * m2) % mod;
*/