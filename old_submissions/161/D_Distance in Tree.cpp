#include <bits/stdc++.h>

#define int long long

using namespace std;

constexpr int mod = 998244353;

vector<vector<int> > g, dp;
int ans = 0;

void dfs (int v, vector<vector<int> > &dp, int p = -1)
{
    int k = dp[0].size() - 1;
    for (int w : g[v])
    {
        if (w != p)
        {
            dfs(w, dp, v);
            for (int i = 1; i < k + 1; ++i)
            {
                dp[v][i] += dp[w][i - 1];
            }
        }
    }
}

void dfs2 (int v, vector<vector<int> > &dp, int p = -1)
{
    int k = dp[0].size() - 1;
    for (int w : g[v])
    {
        if (w != p)
        {
            dfs2(w, dp, v);
            for (int i = 1; i < k; ++i)
            {
                ans += dp[w][i - 1] * (dp[v][k - i] - dp[w][k - i - 1]);
            }
        }
    }
}

void solve()
{
    int n, k;
    cin >> n >> k;
    g = vector<vector<int> > (n);
    vector<vector<int> > dp(n, vector<int> (k + 1));
    for (int i = 0; i < n; ++i)
    {
        dp[i][0] = 1;
    }
    for (int i = 0; i < n - 1; ++i)
    {
        int v, u;
        cin >> v >> u;
        --v; --u;
        g[v].push_back(u);
        g[u].push_back(v);
    }
    dfs(0, dp);
    dfs2(0, dp);
    // cout << ans << "\n";
    ans >>= 1;
    for (int i = 0; i < n; ++i)
    {
        ans += dp[i][k];
    }
    cout << ans << "\n";
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int t;
    // cin >> t;
    t = 1;
    while (t--)
    {
        solve();
    }
}

/*

*/