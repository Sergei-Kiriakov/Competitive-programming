//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("avx,avx2,fma")

#include <bits/stdc++.h>
#include <random>

#define int long long
#define double long double
#define endl "\n"
#define all(x) (x).begin(), (x).end()

using namespace std;

const int mod = 998244353, d = 179;

vector<int> fac;

int bin_pow(int a, int n)
{
    int ans = 1;
    while (n)
    {
        if (n & 1)
            ans = ans * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return ans;
}

int inverse_mod(int a)
{
    return bin_pow(a, mod - 2);
}

int cnk(int n, int k)
{
    return fac[n] * inverse_mod(fac[n - k]) % mod * inverse_mod(fac[k]) % mod;
}

void solve()
{
    int n;
    cin >> n;
    vector<int> dp(n + 10, 1);
    dp[2] = 2;
    for (int i = 3; i < n + 1; ++i)
    {
        dp[i] = (dp[i - 1] + dp[i - 2] * (i - 1)) % mod;
    }
    fac = vector<int> (n + 1, 1);
    for (int i = 2; i < fac.size(); ++i)
        fac[i] = fac[i - 1] * i % mod;
    int ans = 0;
    for (int cnt4 = 0; cnt4 * 4 <= n; ++cnt4)
    {
        int d = cnk(n - 2 * cnt4, 2 * cnt4) * fac[cnt4 * 2] % mod * inverse_mod(fac[cnt4]) % mod;
        ans = (ans + d * dp[n - cnt4 * 4]) % mod;
    }
    cout << ans << endl;
}

int32_t main()
{
//  ofstream cout("sum.out");
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cout << fixed;
    cout.precision(0);
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    int tt = 1;
    cin >> tt;
    while(tt-->0)
    {
        solve();
    }
}


/*
*/