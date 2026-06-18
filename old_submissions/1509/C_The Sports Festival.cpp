#include <bits/stdc++.h>

#define Please return
#define Accepted 0
#define int long long
#define endl "\n"
#define double long double

using namespace std;

constexpr int MAXN = 1e6 + 6, mod1 = 1e9 + 9, d = 179, mod2 = 1e9 + 7;

void solve ()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    vector<vector<int> > dp(n + 1, vector<int> (n + 1, 0));
    for (int sz = 1; sz < n; ++sz)
    {
        for (int l = 0; l + sz < n; ++l)
        {
            int r = l + sz;
            dp[l][r] = a[r] - a[l] + min(dp[l + 1][r], dp[l][r - 1]); 
        }
    }
    cout << dp[0][n - 1] << endl;
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
