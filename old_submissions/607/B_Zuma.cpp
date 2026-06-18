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
    vector<vector<int> > dp(n + 10, vector<int> (n + 10, 1e9));
    for (int i = 0; i < n + 1; ++i)
    {
        dp[i][i] = 1;
        for (int j = 0; j < i; ++j)
            dp[i][j] = 0;
    }
    for (int len = 1; len < n; ++len)
    {
        for (int i = 0; i < n - len; ++i)
        {
            int j = i + len;
            dp[i][j] = min(1 + dp[i + 1][j], dp[i][j]);
            if (i + 1 < n and a[i] == a[i + 1])
                dp[i][j] = min(dp[i][j], 1 + dp[i + 2][j]);
            for (int k = i + 2; k <= j; ++k)
            {
                if (a[i] == a[k])
                    dp[i][j] = min(dp[i][j], dp[i + 1][k - 1] + dp[k + 1][j]);
            }
        }
    }
    cout << dp[0][n - 1] << endl;
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