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

int tele (vector<int>& a, int l, int r)
{
    int ans = 1e9;
    int n = a.size();
    for (int i = max(0ll, l - 1); i <= min(n - 1, r + 1); ++i)
        ans = min(ans, a[i]);
    return ans;
}

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    if (n == 1)
    {
        cout << a[0] << endl;
        return;
    }
//    vector<int> mins(n);
//    mins[0] = min(a[0], a[1]);
//    mins[n - 1] = min(a[n - 1], a[n - 2]);
//    for (int i = 1; i < n - 1; ++i)
//    {
//        mins[i] = min({a[i], a[i - 1], a[i + 1]});
//    }
    vector<vector<int> > dp(n + 1, vector<int> (k + 1, 1e18));
    dp[0][0] = 0;
    for (int i = 0; i < n; ++i)
    {
        int o = 2;
        for (int j = 0; j <= k; ++j)
        {
            dp[i + 1][j] = min(dp[i + 1][j], a[i] + dp[i][j]);
            for (int h = 1; h + j <= k and i + h <= n; ++h)
            {
                int min1 = tele(a, i, i + h - 1);
                dp[i + h][j + h] = min(min1 * h + dp[i][j], dp[i + h][j + h]);
            }
        }
    }
    int ans = 1e18;
    for (int i = 0; i <= k; ++i)
    {
        ans = min(ans, dp[n][i]);
    }
    cout << ans << endl;
}

int32_t main()
{
//    ofstream cout("std.out");
//    ifstream cin("std.in");
    ios::sync_with_stdio(false); cin.tie(nullptr);
//    cout << fixed;
//    cout.precision(7);
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