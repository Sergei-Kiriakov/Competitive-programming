#include <bits/stdc++.h>

#define Please return
#define Accepted 0
#define int long long
#define endl "\n"
#define double long double

using namespace std;

constexpr int MAXN = 1e6 + 6, mod = 1e8;

void solve ()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
        a[i] %= m;
    }
    if (n > m)
    {
        cout << "YES" << endl;
        return;
    }
    vector<vector<bool> > dp(n + 1, vector<bool> (m, false));
    for (int i = 0; i < n; ++i)
    {
        dp[i + 1][a[i]] = true;
    }
    for (int i = 1; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            dp[i + 1][(j + a[i]) % m] = dp[i + 1][(j + a[i]) % m] || dp[i][j];
            dp[i + 1][j] = dp[i + 1][j] || dp[i][j];
        }
    }
    if (dp[n][0])
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0), cerr.tie(0);
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    int tt = 1;
    // cin >> tt;
    while (tt--)
    {
        solve();
    }
}

/*
No brain
*/
