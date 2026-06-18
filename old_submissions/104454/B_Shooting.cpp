//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("avx,avx2,fma")

#include <bits/stdc++.h>

#include <random>

#define int long long
#define double long double
#define endl "\n"
#define all(x) (x).begin(), (x).end()

using namespace std;

const int mod = 1e9 + 7, big = 2e6;

void solve()
{
    int n, k, p;
    cin >> n >> k >> p;
    vector<vector<int> > dp(n + 1, vector<int> (k * n + 1));
    vector<int> pref(k * n + 1, 1);
    dp[0][0] = 1;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j < n * k + 1; ++j)
        {
            if (j > k)
                dp[i][j] = (mod + pref[j - 1] - pref[j - k - 1]) % mod;
            else
                dp[i][j] = pref[j - 1];
        }
        pref[0] = 0;
        for (int j = 1; j < n * k + 1; ++j)
        {
            pref[j] = (pref[j - 1] + dp[i][j]) % mod;
        }
    }
    int ans = 0;
    for (int i = p + 1; i < n * k + 1; ++i)
    {
        ans = (ans + dp[n][i]) % mod;
    }
    cout << ans << endl;
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