//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("avx,avx2,fma")

#include <bits/stdc++.h>

#include <random>

#define int long long
#define double long double
#define endl "\n"
#define all(x) (x).begin(), (x).end()

using namespace std;

const int mod = 1e9 + 93;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    sort(all(a));
    int big = 400;
    vector<vector<int> > dp (n + 1, vector<int> (big, 1e9));
    for (int i = 0; i < big; ++i)
        dp[0][i] = 0;
    for (int i = 1; i < n + 1; ++i)
    {
        for (int j  = 1; j < big; ++j)
        {
            dp[i][j] = min(dp[i - 1][j - 1] + abs(j - a[i - 1]), dp[i][j - 1]);
        }
    }
    int ans = 1e9;
    for (int i = 0; i < big; ++i)
        ans = min(ans, dp[n][i]);
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