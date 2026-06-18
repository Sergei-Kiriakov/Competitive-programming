//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("avx,avx2,fma")

#include <bits/stdc++.h>

#include <random>

#define int long long
#define double long double
#define endl "\n"
#define all(x) (x).begin(), (x).end()

using namespace std;

const int mod = 1e9 + 93, ddl = 179;

void solve()
{
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    vector<int> dp(n + 1, 0);
    for (int i = 0; i < n; ++i)
    {
        int sum1 = 0;
        int max_sum = 0;
        for (int j = 0; j < m and i - j > -1; ++j)
        {
            sum1 += a[i - j];
            dp[i + 1] = max(dp[i - j] + sum1 - k, dp[i + 1]);
        }
    }
    int ans = 0;
    for (int i = 0; i < n + 1; ++i) ans = max(ans, dp[i]);
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
//    cin >> tt;
    while(tt-->0)
    {
        solve();
    }
}


/*
*/